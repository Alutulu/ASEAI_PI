#!/usr/bin/python3

import cv2 as cv
from traitement import *

def main():
    print("Version d'OpenCV : ", cv.__version__)
    path = "./images/lezard.jpg"
    img_ori = cv.imread(path)
    img_grey = findEdge(img_ori)
    cv.imshow("Image grise", img_grey)
    cv.waitKey(0) 

if __name__ == "__main__":
    main()