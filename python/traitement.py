import cv2 as cv

class Traitement():

    def findEdge(image):
        img_gris = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
        img_blur = cv.GaussianBlur(img_gris, (3,3), 0) 
        edges = cv.Canny(image=img_blur, threshold1=100, threshold2=200) # Canny Edge Detection
        return edges

    def findFace(image, face_detector):
            grey = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
            faces = face_detector.detectMultiScale(grey, 1.1, 5)

            if len(faces) > 0:

                index_max_face = 0
                max_size_face = 0

                if len(faces) > 1:
                    for i, face in enumerate(faces):
                        size_face = (face[2] + face[3]) / 2
                        if size_face > max_size_face:
                            max_size_face = size_face
                            index_max_face = i

                x, y, width, height = faces[index_max_face] 
                radius = (width + height) / 4
                center_x = x + width / 2
                center_y = y + height / 2
                return int(center_x), int(center_y), int(radius)
            else:
                return None
    
    def valeurs_zones(zones):
        nb_zones = len(zones) + 1
        valeurs_zones = range(int(-(nb_zones -1) / 2), int(1+ (nb_zones -1) / 2))
        return valeurs_zones
    
    def getSeuilsX(image, zones):
        height, width = image.shape[0], image.shape[1]
        return [int((width / 100)*zones[i]) for i in range(len(zones))]

    def drawSeuils(image, seuils_x):
        height, width = image.shape[0], image.shape[1]
        for seuil in seuils_x:
            cv.line(image,(seuil,0),(seuil,height-1),(255,0,0),3)

    def update_target(visage, valeurs_zones, seuils_x):
        nb_seuils = len(seuils_x)
        ind_zone = 0
        while visage.x >= seuils_x[ind_zone] and ind_zone < nb_seuils:
            ind_zone += 1
            if ind_zone >= nb_seuils or visage.x < seuils_x[ind_zone]:
                break
        return valeurs_zones[ind_zone]