import cv2
import numpy as np
def test():

    # basic good test


    img = cv2.imread('photo.jpg', 0)
    # rows,cols = img.shape

    # M = np.float32([[1,0,100],[0,1,50]])
    # dst = cv2.warpAffine(img,M,(cols,rows))

    cv2.imshow('img', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()





def capture_video():

    # hence test is complet for video test . good work in python
    cap = cv2.VideoCapture(0)
    while (True):
        # Capture frame-by-frame
        ret, frame = cap.read()

        # Our operations on the frame come here
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Display the resulting frame
        cv2.imshow('frame', gray)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # When everything done, release the capture
    cap.release()
    cv2.destroyAllWindows()


# test()

capture_video()
import tensorflow as tf
print("hhiiiiiiiiiiiiiiiii")
