from tkinter import *
from tkinter import messagebox
from pytube import YouTube


BACKGROUND_COLOR = "#B1DDC6"
#----------------------------Audio Download-------------------------#
# def audio():
#     link = link_input.get()
#     path = path_input.get()
#     if len(link) == 0 or len(path) == 0:
#         messagebox.showerror(title="error", message="You miss something to fill")
#     else:
#         pass


#-----------------------------Video Download-----------------------#
def videoDownload():
    link = link_input.get()
    path = path_input.get()

    if len(link) == 0 or len(path) == 0:
        messagebox.showerror(title="error", message="You miss something to fill")
    else:
        yt = YouTube(link)
        vid = yt.streams.first()
        messagebox.showinfo(title="Downloading", message="Wait your Video is in Downloading Process")
        vid.download(path)
        messagebox.showinfo(title="Download info", message=f"Your Download is Compelete\nYour video is in {path}")


#------------------------------Title of the video------------------------#

def title():
    link = link_input.get()
    path = path_input.get()
    if len(link) == 0 or len(path) == 0:
        messagebox.showerror(title="error", message="You miss something to fill")
    else:
        yt = YouTube(link)
        title = yt.title
        duration = yt.length
        views = yt.views
        videoName.config(text=f"title: {title}\nduration: {duration}\nViews: {views}")




#-----------------------------------UI----------------------------------#
window = Tk()
window.title("Youtube Video Downloader")
window.config(padx=80, pady=80, bg=BACKGROUND_COLOR)


#nput
link_input= Entry(width=21)
link_input.focus()
link_input.grid(column=1, row=1, columnspan=2)

path_input = Entry(width=21)
path_input.grid(column=1, row=3, columnspan=2)

# #label
path_label = Label(text="Where you Want to download the video or Music\n past the location here", bg=BACKGROUND_COLOR)
path_label.grid(column=1, row=2)

videoName = Label(text="Title of the YouTube", bg=BACKGROUND_COLOR)
videoName.grid(column=1, row=4, columnspan=2)

link_label = Label(text="Link in down here", bg=BACKGROUND_COLOR)
link_label.grid(column=1, row=0, columnspan=2)

process = Label(text="", bg=BACKGROUND_COLOR)
process.grid(column=1, row=8, columnspan=2)


#Video
title_button = Button(text="Load the Song", bg=BACKGROUND_COLOR, command=title)
title_button.grid(column=1, row=5, columnspan=2)

video_download = Button(text="Download Video", bg=BACKGROUND_COLOR, command=videoDownload)
video_download.grid(column=1, row=6, columnspan=2)

# audioDownload = Button(text="Download Audio", bg=BACKGROUND_COLOR, command=audio)
# audioDownload.grid(column=1, row=7)


window.mainloop()