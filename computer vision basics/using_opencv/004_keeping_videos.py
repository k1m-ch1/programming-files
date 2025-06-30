import numpy as np
import cv2 as cv
import sys

# argument is the index of camera (if have multiple cameras)
cap = cv.VideoCapture(0)

# fourcc is 4-byte code used to speify the video codec
# video codec (coder, decoder)
fourcc = cv.VideoWriter_fourcc("XVID")
out = cv.VideoWriter("output.avi", fourcc, 20.0, (640, 480))

try:
    while cap.isOpened():
        # ret is True or False for whether it is read correctly, somehow can also be used to check for the end of the footage??
        ret, frame = cap.read()
        
        if not ret:
            print("Can't receive frame. Exitting...")
            break
        
        cv.imshow("frame", frame)
        if cv.waitKey(1) == ord('q'):
            break
finally:
    cap.release()
    cv.destroyAllWindows()
    
    
    
