import cv2 as cv

def findEdge(image):
    img_gris = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    img_blur = cv.GaussianBlur(img_gris, (3,3), 0) 
    edges = cv.Canny(image=img_blur, threshold1=100, threshold2=200) # Canny Edge Detection
    return edges