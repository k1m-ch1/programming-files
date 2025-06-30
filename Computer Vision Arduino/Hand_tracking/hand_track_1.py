import cv2  # computer vision library. 
import mediapipe as mp # Mediapipe library is property of google. Machine learning algorithms ig
import time

hands = mp.solutions.hands.Hands() # Go throughs a whole bunch of stuff to create a hands object.
mpdraw = mp.solutions.drawing_utils # Is used to draw on the img later on. 

capture = cv2.VideoCapture(0) # Activates the camera
while True:
  success, img = capture.read() # Reads the captured image, returns a bool and an image
  imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB) # Take in an image and returns the RGB data ig
  results = hands.process(imgRGB) # Takes in the RGB data and runs through complex algorithms to return the cords of hand
  # print(results.multi_hand_landmarks)
  if (rs:=results.multi_hand_landmarks) != None:
    for handLandmarks in rs:
      mpdraw.draw_landmarks(img, handLandmarks, mp.solutions.hands.HAND_CONNECTIONS) # Place those points at the specified cord\
      # Connects the points of the hand
  cv2.imshow("Image", img) # Show the image on a new window
  cv2.waitKey(1)  # Delay
  
