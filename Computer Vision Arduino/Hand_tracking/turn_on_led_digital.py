import cv2 as cv
import mediapipe as mp
import serial
import time
import math


def initialize_video(video_id=0):
  """Opens the camera and initalize a video object for capturing images.

  Args:
      video_id (int, optional): Set the video id. Defaults to 0.

  Returns:
      video_object: opens the camera 
  """
  return cv.VideoCapture(video_id)

def initialize_hand(max_num_of_hands=1):
  """initalize a hand object for complex alg running on image.

  Args:
      max_num_hands (int, optional): maximum number of hands detected. Defaults to 1.
  Returns:
      Hand_object: returns a object for all hands detected.
  """
  return mp.solutions.hands.Hands(max_num_hands=max_num_of_hands)

def initialize_serial_com(com_port, baud_rate=9600):
  """initialize a connection to serial port. 

  Args:
      com_port (string): com port. takes in "COMX" ex. "COM4"
      baud_rate (int): baud rate. Defaults to 9600.

  Returns:
      Serial_object: object connected for sending data or recv data from serial port.
  """
  return serial.Serial(com_port, baudrate=baud_rate)

def get_distance(all_hand_landmark, PALM_OF_HAND, FINGER_TIP):
  """Apply the formula hypothenuse(y'-y, x'-x)

  Args:
      all_hand_landmark (list): _description_
      PALM_OF_HAND (int): _description_
      FINGER_TIP (int): _description_

  Returns:
      Integer: _description_
  """
  return math.hypot(all_hand_landmark[FINGER_TIP][0]-all_hand_landmark[PALM_OF_HAND][0],all_hand_landmark[FINGER_TIP][1]-all_hand_landmark[PALM_OF_HAND][1])

def tip_to_palm_distance(hand_landmark_pixels):
  PALM_OF_HAND = 0
  TIP_OF_HAND = [4,8,12,16,20] # Cord tip of THUMB, INDEX, MIDDLE, RING, PINKY finger respectively
  ret_list = list()
  for i in TIP_OF_HAND:
    ret_list.append(int(get_distance(hand_landmark_pixels, PALM_OF_HAND,i)))
  return ret_list

def find_distance_in_percentage(current_distance, min_max_distance):
  """Distance according to min value and max value. 
  For example: a min distance of 10 and a max distance of 100 will give 0 if current distance
  is 0 and 1 if current distance is 100. If current_distance is above or below this point, it will give a result of x > 1 or x < 0.

  Args:
      current_distance (list): current distance of all tip to palm
      min_max_distance (list): constants that determine the range

  Returns:
      list: list of distance in percentage
  """
  return [round((current_distance[x]-min_max_distance[x][0])/(min_max_distance[x][1]-min_max_distance[x][0]),3) for x in range(len(min_max_distance))]
  
def scale_and_format_string(percentage_distance, scaler):
  """Scale the string, convert percentage based on scaler. Applies percentage_distance*scaler

  Args:
      percentage_distance (_type_): _description_
      scaler (_type_): _description_

  Returns:
      ret_string: string ready to be transferred to arduino program. Protocol is ,THUMB,INDEX,MIDDLE,RING,PINKY,
  """
  ret_string = ","
  for i in percentage_distance:
    if i < 0: ret_string += '0,'
    elif i > 1: ret_string += '255,'
    else: ret_string += f'{int(i*scaler)},'
  return ret_string

def scale_and_format_string_in_digital(percentage_distance, scaler):
  """scale and format the string in to 0 and 1 decided by whether it's below or above 0.5.

  Args:
      percentage_distance (list): _description_
      scaler (int): _description_

  Returns:
      string: _description_
  """
  ret_str = ","
  for i in percentage_distance:
    if i < 0.5: ret_str += f"0,"
    else: ret_str += f"{scaler},"
  return ret_str

MIN_AND_MAX_DISTANCE = [(110, 220), (90, 306), (70, 320), (60, 303), (50, 249)]
video_object = initialize_video()
all_hand_object = initialize_hand(1)
my_Serial = initialize_serial_com('COM4', 9600)
DIGITAL_OR_ANALOG = {"yes": scale_and_format_string_in_digital, "no": scale_and_format_string}
inputted_data = None
while inputted_data not in DIGITAL_OR_ANALOG.keys():
  inputted_data = input("Do you want digital mode? If no then use analog mode. ")
while True:
  success, img_object = video_object.read()
  RGB_DATA = cv.cvtColor(img_object, cv.COLOR_BGR2RGB)
  all_hand_cord = all_hand_object.process(RGB_DATA) # Mark all of the point of hands
  if (temp_cord:=all_hand_cord.multi_hand_landmarks) != None:
    hand_cord = temp_cord[0]  # get the first hand data
    mp.solutions.drawing_utils.draw_landmarks(img_object, hand_cord, mp.solutions.hands.HAND_CONNECTIONS) # Draw points on image based on cords
    point_cords = [x for x in hand_cord.landmark] # cord point object, has x and y and is in percentage
    point_x_y_cords_pixels = [(int(point_cord.x*img_object.shape[1]), int(point_cord.y*img_object.shape[0])) for point_cord in point_cords]
    all_distance = tip_to_palm_distance(point_x_y_cords_pixels) # Return a list of tip to palm distance for each finger
    percentage_distance = find_distance_in_percentage(all_distance, MIN_AND_MAX_DISTANCE) # Convert it back to percentage based on min and max.
    string_to_send = DIGITAL_OR_ANALOG[inputted_data](percentage_distance, 255)
    print(string_to_send)
    my_Serial.write(string_to_send.strip().encode())
  cv.imshow("Image", img_object)  # Renders the Image
  cv.waitKey(1)
  time.sleep(0.01)