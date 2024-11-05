#!/usr/bin/python3

PC = True

import cv2 as cv
import time
from Visage import Visage
from traitement import *
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

    old_visage = Visage()
    sample_visages = []
    nb_iter = 0

    if PC:
        # Camera du PC
        cam = cv.VideoCapture(0)

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
            if nb_iter >= 5 and len(sample_visages) >= 3:
                old_visage = Visage.visage_moyen(sample_visages)
                sample_visages = []
                nb_iter = 0
        if old_visage.radius > 0:
            old_visage.drawCenter(im)
            target = Traitement.update_target(old_visage, valeurs_zones, seuils_x)
        Traitement.drawSeuils(im, seuils_x)
        # Write the frame to the output file
        # out.write(frame)

        # Display the captured frame
        cv.imshow('Camera', im)

        # Press 'q' to exit the loop
        if cv.waitKey(1) == ord('q'):
            break

        # Release the capture and writer objects
        if PC:
            cam.release()
        # out.release()
        cv.destroyAllWindows()

if __name__ == "__main__":
    main()
