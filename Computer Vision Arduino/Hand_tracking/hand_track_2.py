import mediapipe as mp
import cv2 as cv
import serial
import math
import time

def get_hypothenuse(obj1, obj2):
  """ Cord Object, Cord Object -> distance
  Find the distance of coord between one point and another point
  """
  return math.hypot(abs(obj1.x-obj2.x), abs(obj1.y-obj2.y))

def find_percentage(max_and_min, val):
  """Tuple, Number -> Float
  Find the percentage according to min and max values"""
  return (val - max_and_min[1])/(max_and_min[0]-max_and_min[1])

def get_scaled_string(percentage_rn):
  """List -> String
  Returns a string ready to be parsed to arduino. Scales the percentage accordingly."""
  ret_string = ","
  for i in percentage_rn:
    if i < 0: ret_string+= str(int(0)) + ','
    elif i > 1: ret_string+= str(int(255)) + ','
    else:
      ret_string += str(int(255*i)) + ','
  return ret_string

# Initiation of camera and hands 
my_vid = cv.VideoCapture(0)
hands = mp.solutions.hands.Hands(max_num_hands=1)
all_points = None # a list containing every point of the hand
my_serial = serial.Serial('COM4', 9600)
time.sleep(3)
while True:
  success, frame_img = my_vid.read() # Capturing a frame
  
  # Collects hand data 
  RGB_DATA = cv.cvtColor(frame_img, cv.COLOR_BGR2RGB)
  hand_cords = hands.process(RGB_DATA)
  if (all_cord:=hand_cords.multi_hand_landmarks) != None: # is iterable containing several hands.
    for cords in all_cord: # cords has data for one hand.
      mp.solutions.drawing_utils.draw_landmarks(frame_img, cords, mp.solutions.hands.HAND_CONNECTIONS) # rendering the points in picture
      all_points = [x for x in cords.landmark]
      for i in range(len(all_points)):  # Scaling the percentage to pixels
        all_points[i].x = int(all_points[i].x*frame_img.shape[1])
        all_points[i].y = int(all_points[i].y*frame_img.shape[0])

  MAX_MIN_FINGER = [(85,40),(130,20), (145,21), (142,20), (110, 20)]
  
  if all_points != None:
    # Thumb, index, middle, ring, pinky  
    all_finger_distance = [get_hypothenuse(all_points[2], all_points[4]), get_hypothenuse(all_points[5], all_points[8]),
                          get_hypothenuse(all_points[9], all_points[12]),get_hypothenuse(all_points[13], all_points[16]),
                          get_hypothenuse(all_points[17], all_points[20])]  # Stores the displacement of tip to lower joint (idk what it's called)
    percentage_rn = [find_percentage(MAX_MIN_FINGER[x], all_finger_distance[x]) for x in range(5)] # Get the percentage of how close the tip is to the lower joint
    string_to_send = get_scaled_string(percentage_rn) # Get a string ready to be parsed
    average_lighting = sum(percentage_rn)/5
    cv.rectangle(frame_img,(10,(300-int((290*average_lighting))+10)), (25,300), (0,255,0), cv.FILLED)
    cv.putText(frame_img, f"Avg {round(average_lighting*100,2)}%", (10,350), cv.FONT_HERSHEY_COMPLEX, 1, (0, 0, 255) , 3)
    print(string_to_send)
    my_serial.write(string_to_send.strip().encode('utf-8')) # Sends the string
  # Renders the image
  cv.rectangle(frame_img,(10,25), (25, 300), (0,255,0), 4)
  cv.imshow("Image", frame_img) # Renders the image
  cv.waitKey(1)
  time.sleep(0.01)