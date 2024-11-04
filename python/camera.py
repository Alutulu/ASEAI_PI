#!/usr/bin/python3

PC = False

import cv2 as cv
import time
from traitement import *
if not PC:
    from picamera2 import Picamera2, Preview

def main():
    print("Version d'OpenCV : ", cv.__version__)
    # path = "./images/lezard.jpg"
    # img_ori = cv.imread(path)

    face_detector = cv.CascadeClassifier("../assets/haarcascade_frontalface_default.xml")

    if PC:
        # Camera du PC
        cam = cv.VideoCapture(0)

        # Get the default frame width and height
        frame_width = int(cam.get(cv.CAP_PROP_FRAME_WIDTH))
        frame_height = int(cam.get(cv.CAP_PROP_FRAME_HEIGHT))

        # # Define the codec and create VideoWriter object
        # fourcc = cv.VideoWriter_fourcc(*'mp4v')
        # out = cv.VideoWriter('output.mp4', fourcc, 20.0, (frame_width, frame_height))

        while True:
            ret, im = cam.read()
            grey = cv.cvtColor(im, cv.COLOR_BGR2GRAY)
            faces = face_detector.detectMultiScale(grey, 1.1, 5)

            for (x, y, w, h) in faces:
                cv.rectangle(im, (x, y), (x + w, y + h), (0, 255, 0))
            # Write the frame to the output file
            # out.write(frame)

            # Display the captured frame
            cv.imshow('Camera', im)

            # Press 'q' to exit the loop
            if cv.waitKey(1) == ord('q'):
                break

        # Release the capture and writer objects
        cam.release()
        # out.release()
        cv.destroyAllWindows()

    else:

        cv.startWindowThread()

        picam2 = Picamera2()
        picam2.configure(picam2.create_preview_configuration(main={"format": 'XRGB8888', "size": (640, 480)}))
        picam2.start()

        while True:
            im = picam2.capture_array()

            grey = cv.cvtColor(im, cv.COLOR_BGR2GRAY)
            faces = face_detector.detectMultiScale(grey, 1.1, 5)

            for (x, y, w, h) in faces:
                cv.rectangle(im, (x, y), (x + w, y + h), (0, 255, 0))

            cv.imshow("Camera", im)
            cv.waitKey(1)

        # OFFICIAL EXAMPLE ----------------------------
        # picam2 = Picamera2()
        # camera_config = picam2.create_preview_configuration()
        # picam2.configure(camera_config)
        # picam2.start_preview(Preview.QTGL)
        # picam2.start()
        # time.sleep(10)
        # picam2.capture_file("test.jpg")
    
    	#OLD ------------------------------------------
        #capture image
        #camera = PiCamera()
        #rawImage = PiRGBArray(camera)

        #time.sleep(0.1)
        #camera.capture(rawImage, format="rgb")
        #img_ori = rawImage.array

        #display captured image in an OpenCV window
        #cv.imshow("Image", img_ori)
        #cv.waitKey(0)

        #record captured image on MicroSD card
        #cv.imwrite("test.jpg", img_ori)
        #img_grey = findEdge(img_ori)
        #cv.imshow("Image grise", img_grey)
        #cv.waitKey(0) 

if __name__ == "__main__":
    main()
