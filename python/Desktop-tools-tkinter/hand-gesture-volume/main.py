import numpy as np
import time
import pyautogui as key
import PIL
from PIL import Image,ImageTk
import cv2
import tkinter as tk
from tkinter import *
import mediapipe as mp
import math
import speech_recognition as sp
import pyttsx3 as tx
import pywhatkit as kit
import datetime
import wikipedia as wiki

def p():
    listener=sp.Recognizer()
    engine=tx.init()

    def talk(sentence):
        engine.say('Hi i am your speaker , and now')
        engine.say(sentence)
        engine.runAndWait()
    def take_command():
        try:
            with sp.Microphone() as source:
                print('hearing...')
                voice=listener.listen(source)
                command=listener.recognize_google(voice)
                command=command.lower()
                print(command)
                if('speaker' in command):
                    print(command)

        except EXCEPTION as error:
            print('error',error)

        return command


    def run_techmoji():
        command=take_command()
        print(command)
        if('increase' in command):
            song=command.replace('increase','')
            volume.SetMasterVolumeLevel(maxvol, None)
            talk('volume increased to hundred percentage')


        elif('decrease' in command):
            song=command.replace('decrease','')
            volume.SetMasterVolumeLevel(minvol, None)
            talk('volume decrease to zero percentage')

        elif(not ('time' and 'play') in command):
            info=wiki.summary(command,1)
            talk(info)




    run_techmoji()

def noaudio():
    key.hotkey('volumemute')

def volrise():
    key.hotkey('volumeup')

def vollow():
    key.hotkey('volumedown')


width, height = 800, 600
cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, width)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
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
volume.GetMute()
#volume.GetMasterVolumeLevel()
vol=volume.GetVolumeRange()
minvol=vol[0]
maxvol=vol[1]
vol=0
volbar=400


root = Tk()
root.bind('<Escape>', lambda e: root.quit())
root.iconbitmap('assets/icons8-stretch-tool-64.png')
root.title(" Volume Controller")
w, h = root.winfo_screenwidth(), root.winfo_screenheight()
root.geometry("%dx%d+0+0" % (w, h))
#labels
tk.Label(root,text="Gesture Volume Controller",font=('Arial Bold',18)).place(x=50,y=80)
tk.Label(root,text="Speak to adjust volume",font=('Arial',14),fg='blue2').place(x=250,y=190)
tk.Label(root,text="Mute",font=('Arial',14),fg='blue2').place(x=250,y=360)
tk.Label(root,text="Volume ( - )",font=('Arial',14),fg='blue2').place(x=250,y=565)
tk.Label(root,text="Volume ( + )",font=('Arial',14),fg='blue2').place(x=250,y=765)

clip = PhotoImage(file="assets/clip1-min_34.png")
tk.Label(root,image=clip).place(x=600,y=700)
tk.Label(root,text='Show your finger infront of camera to adjust your  volume.' '\n'
                   'Thumb and index finger are used to adjust the volume').place(x=900,y=800)


#images
mic = ImageTk.PhotoImage(PIL.Image.open("assets/icons8-microphone-64.png"))
mute = ImageTk.PhotoImage(PIL.Image.open("assets/icons8-no-audio-64.png"))
lowvol=ImageTk.PhotoImage(PIL.Image.open("assets/icons8-low-volume-64.png"))
highvol=ImageTk.PhotoImage(PIL.Image.open("assets/icons8-audio-64.png"))

#buttons
Button(root,image=lowvol,command=vollow).place(x=150,y=550)
Button(root,image=highvol,command=volrise).place(x=150,y=750)
Button(root,image=mute,command=noaudio).place(x=150,y=350)
Button(root, text = 'Click Me !', image =mic,command=p).place(x=150,y=180)

#camera-pack
lmain = Label(root)
lmain.pack(side=TOP,pady=100)

global pTime
pTime=0

def show_frame():
    _, frame = cap.read()
    frame = cv2.flip(frame, 1)
    cv2image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = hands.process(cv2image)
    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            for id,lm, in enumerate(handLms.landmark):
                h,w,c =cv2image.shape
                cx,cy = int(lm.x*w),int(lm.y*h)
                if(id==4 ):
                    x1=cx
                    y1=cy
                    cv2.circle(cv2image,(cx,cy),25,(255,0,255),cv2.FILLED)


                if(id==8):
                    x2=cx
                    y2=cy
                    cv2.circle(cv2image,(cx,cy),25,(255,0,255),cv2.FILLED)

            mpDraw.draw_landmarks(cv2image,handLms,mpHands.HAND_CONNECTIONS)
            cv2.line(cv2image,(x1,y1),(x2,y2),(255,0,0),3)
            midx=(x1+x2)//2
            midy=(y1+y2)//2
            cv2.circle(cv2image,(midx,midy),15,(255,0,255),cv2.FILLED)
            length =math.hypot(x1-x2,y1-y2)
            vol=np.interp(length,[50,300],[minvol,maxvol])
            volbar=np.interp(length,[50,300],[400,150])
            volume.SetMasterVolumeLevel(vol, None)
            cv2.rectangle(cv2image,(50,150),(85,400),(0,255,0),3)
            cv2.rectangle(cv2image,(50,int(volbar)),(85,400),(0,0,0),cv2.FILLED )          #print(length)
            if length<50:
                cv2.circle(cv2image,(midx,midy),15,(0,0,255),cv2.FILLED)

    cTime=time.time()
    global pTime
    fps=1/(cTime-pTime)
    pTime=cTime
    cv2.putText(cv2image,f'FPS:{int(fps)}', (40,50),cv2.FONT_HERSHEY_COMPLEX,1,(255,0,0),3)
    img = PIL.Image.fromarray(cv2image)
    imgtk = ImageTk.PhotoImage(image=img)
    lmain.imgtk = imgtk
    lmain.configure(image=imgtk)
    lmain.after(10, show_frame)

show_frame()
root.mainloop()
