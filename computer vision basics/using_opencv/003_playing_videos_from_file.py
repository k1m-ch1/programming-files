import numpy as np
import cv2 as cv
import sys

# argument is the index of camera (if have multiple cameras)
cap = cv.VideoCapture("../videos/virtual_insanity.avi")
try:
    while True:
        # ret is True or False for whether it is read correctly, somehow can also be used to check for the end of the footage??
        ret, frame = cap.read()

        if not ret:
            print("Can't receive frame. Exitting...")
            break

        # it seems that flags are really weird in opencv
        # hmmm... they just store integers as flags...
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

        cv.imshow("frame", gray)
        if cv.waitKey(1) == ord('q'):
            break
finally:
    cap.release()
    cv.destroyAllWindows()
    
    
    
