import cv2
import numpy as np
import time
import math
import mediapipe as mp
cap =cv2.VideoCapture(0)
pTime=0
mpHands = mp.solutions.hands
hands = mpHands.Hands(min_detection_confidence=0.7)
mpDraw=mp.solutions.drawing_utils
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(
    IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))
#volume.GetMute()
#volume.GetMasterVolumeLevel()
vol=volume.GetVolumeRange()
minvol=vol[0]
maxvol=vol[1]
vol=0
volbar=400
#volume.SetMasterVolumeLevel(-20.0, None)
while True:
    success,img=cap.read()
    imgRGB= cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    results = hands.process(imgRGB)

    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            for id,lm, in enumerate(handLms.landmark):
                h,w,c =img.shape
                cx,cy = int(lm.x*w),int(lm.y*h)
                if(id==4 ):#or id==8):
                    x1=cx
                    y1=cy
                    cv2.circle(img,(cx,cy),25,(255,0,255),cv2.FILLED)
                    #print(id,x1,y1)

                    #cv2.line(img,(cx,cy),5,(255,0,0),3)

                if(id==8):#or id==8):
                    x2=cx
                    y2=cy
                    cv2.circle(img,(cx,cy),25,(255,0,255),cv2.FILLED)
                    #print(id,x2,y2)
            cv2.line(img,(x1,y1),(x2,y2),(255,0,0),3)
            midx=(x1+x2)//2
            midy=(y1+y2)//2
            cv2.circle(img,(midx,midy),15,(255,0,255),cv2.FILLED)
            length =math.hypot(x1-x2,y1-y2)
            vol=np.interp(length,[50,300],[minvol,maxvol])
            volbar=np.interp(length,[50,300],[400,150])
            volume.SetMasterVolumeLevel(vol, None)
            cv2.rectangle(img,(50,150),(85,400),(0,255,0),3)
            cv2.rectangle(img,(50,int(volbar)),(85,400),(0,0,0),cv2.FILLED )          #print(length)
            if length<50:
                cv2.circle(img,(midx,midy),15,(0,0,255),3)
            mpDraw.draw_landmarks(img,handLms,mpHands.HAND_CONNECTIONS)

    cTime=time.time()
    fps=1/(cTime-pTime)
    pTime=cTime
    cv2.putText(img,f'FPS:{int(fps)}', (40,50),cv2.FONT_HERSHEY_COMPLEX,1,(255,0,0),3)
    cv2.imshow('img',img)
    cv2.waitKey(1)

