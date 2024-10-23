#!/usr/bin/python3

import cv2 as cv
import time
from traitement import *
from picamera import PiCamera
from picamera.array import PiRGBArray

def main():
    print("Version d'OpenCV : ", cv.__version__)
    # path = "./images/lezard.jpg"
    # img_ori = cv.imread(path)

    #capture image
    camera = PiCamera()
    rawImage = PiRGBArray(camera)
    time.sleep(0.1)
    camera.capture(rawImage, format="rgb")
    img_ori = rawImage.array

    #display captured image in an OpenCV window
    cv.imshow("Image", img_ori)
    cv.waitKey(0)

    #record captured image on MicroSD card
    cv.imwrite("test.jpg", img_ori)
    img_grey = findEdge(img_ori)
    cv.imshow("Image grise", img_grey)
    cv.waitKey(0) 

if __name__ == "__main__":
    main()