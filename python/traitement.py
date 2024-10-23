import cv2 as cv

def findEdge(image):
    img_gris = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    img_blur = cv.GaussianBlur(img_gris, (3,3), 0) 
    sobelx = cv.Sobel(src=img_blur, ddepth=cv.CV_64F, dx=1, dy=0, ksize=5) # Sobel Edge Detection on the X axis
    sobely = cv.Sobel(src=img_blur, ddepth=cv.CV_64F, dx=0, dy=1, ksize=5) # Sobel Edge Detection on the Y axis
    sobelxy = cv.Sobel(src=img_blur, ddepth=cv.CV_64F, dx=1, dy=1, ksize=5) # Combined X and Y Sobel Edge Detection
    edges = cv.Canny(image=img_blur, threshold1=100, threshold2=200) # Canny Edge Detection
    return edges