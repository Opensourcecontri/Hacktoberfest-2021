import win32clipboard
import time
import threading
from rich import print
import os
counter = 0
clips = list()


def processInput():
    while True:

        choice = int(input(">>> "))
        if choice > len(clips):
            print("Invalid choice")
            continue
        win32clipboard.OpenClipboard()
        win32clipboard.EmptyClipboard()
        win32clipboard.SetClipboardText(clips[choice], win32clipboard.CF_TEXT)
        win32clipboard.CloseClipboard()


t = threading.Thread(target=processInput)
t.start()

while True:
    win32clipboard.OpenClipboard()
    try:
        data = win32clipboard.GetClipboardData()
    except:
        data = ""
    win32clipboard.CloseClipboard()

    if data not in clips:
        clips.append(data)
        os.system("cls")
        print(clips)

    time.sleep(0.5)
