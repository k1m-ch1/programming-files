import cv2 as cv
import sys


img = cv.imread("../images/mona_lisa.jpg", cv.IMREAD_GRAYSCALE)

if img is None:
    sys.exit("Couldn't find the image")

cv.imshow("Display window", img)
k = cv.waitKey(0)

if k == ord("s"):
    cv.imwrite("../output/mona_lisa.jpg", img)
