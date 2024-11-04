import cv2 as cv

class Visage():

    x = 0
    y = 0
    radius = 0

    def __init__(self, x = 0, y = 0, radius = 0) -> None:
        self.x = x
        self.y = y
        self.radius = radius

    def drawCenter(self, image):
        return cv.circle(image, (self.x,self.y), radius=self.radius, color=(0, 0, 255), thickness=2)
    
    def visage_moyen(visages):
        x_moy, y_moy, radius_moy = 0, 0, 0
        for visage in visages:
            x_moy += visage.x
            y_moy += visage.y
            radius_moy += visage.radius
        x_moy /= len(visages)
        y_moy /= len(visages)
        radius_moy /= len(visages)
        return Visage(int(x_moy), int(y_moy), int(radius_moy))