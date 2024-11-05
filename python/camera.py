#!/usr/bin/python3

PC = False
SAMPLE_SIZE = 3
FACES_NECESSARY = 2

import cv2 as cv
import time
from Visage import Visage
from traitement import *
import subprocess
if not PC:
    from picamera2 import Picamera2, Preview

def main():
    print("Version d'OpenCV : ", cv.__version__)
    # path = "./images/lezard.jpg"
    # img_ori = cv.imread(path)

    zones = (25, 45, 55, 75) # Attention, doit avoir un nombre d'éléments pair
    valeurs_zones = Traitement.valeurs_zones(zones)
    seuils_x = []

    face_detector = cv.CascadeClassifier("../assets/haarcascade_frontalface_default.xml")

    target = None

    old_visage = None
    sample_visages = []
    nb_iter = 0


    if PC:
        # Camera du PC
        cam = cv.VideoCapture(0)

        # Get the default frame width and height
        # frame_width = int(cam.get(cv.CAP_PROP_FRAME_WIDTH))
        # frame_height = int(cam.get(cv.CAP_PROP_FRAME_HEIGHT))

        # # Define the codec and create VideoWriter object
        # fourcc = cv.VideoWriter_fourcc(*'mp4v')
        # out = cv.VideoWriter('output.mp4', fourcc, 20.0, (frame_width, frame_height))

    else:

        cv.startWindowThread()

        picam2 = Picamera2()
        picam2.configure(picam2.create_preview_configuration(main={"format": 'RGB888', "size": (640, 480)}))
        picam2.start()

    while True:
        if PC :
            ret, im = cam.read()
        else :
            im = picam2.capture_array()

        if len(seuils_x) == 0:
            seuils_x = Traitement.getSeuilsX(im, zones)
        res = Traitement.findFace(im, face_detector)
        nb_iter += 1
        if res is not None:
            new_face = Visage(*res)
            sample_visages.append(new_face)
        if nb_iter >= SAMPLE_SIZE:
            if len(sample_visages) >= FACES_NECESSARY:
                old_visage = Visage.visage_moyen(sample_visages)
                nb_iter = 0
            else:
                old_visage = None
                target = None
            sample_visages = []
            nb_iter = 0
        if old_visage is not None:
            old_visage.drawCenter(im)
            target = Traitement.update_target(old_visage, valeurs_zones, seuils_x)
        if old_visage is None:
            target = 0
        Traitement.drawSeuils(im, seuils_x)
        if target is not None :
            startCProgram(target)
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

def startCProgram(target):
    sens = 0 if target < 0 else 1
    velocity = 0
    if target == -2 or target == 2:
        velocity = 80
    elif target == -1 or target == 1:
        velocity = 40
    print("Lance programme C avec ", velocity, sens)
    subprocess.run(["../build/ASEAI_PI", str(velocity), str(sens)])

if __name__ == "__main__":
    main()