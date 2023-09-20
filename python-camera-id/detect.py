import os
import cv2
import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
import serial
import time

def add_face_id():
    face_id = face_id_entry.get()
    if face_id:
        cv2.imwrite(f"face_{face_id}.jpg", frame)
        print(f"Face ID {face_id} added.")
    else:
        print("Please enter a valid Face ID.")

def search_face():
    face_id = face_id_entry.get()
    if face_id:
        ret, frame = cap.read()
        if ret:
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            faces = face_cascade.detectMultiScale(gray, scaleFactor=1.3, minNeighbors=5, minSize=(30, 30))
            
            for (x, y, w, h) in faces:
                cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
                
            if len(faces) > 0:
                print(f"Face ID {face_id} found.")
                ser.write(b'O')
            else:
                print(f"Face ID {face_id} not found.")
                ser.write(b'F')
        else:
            print("Error capturing frame from camera.")
    else:
        print("Please enter a valid Face ID.")


def update_frame():
    global frame
    ret, frame = cap.read()  
    if ret:
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        frame = cv2.resize(frame, (width, height))

        gray = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY)
        faces = face_cascade.detectMultiScale(gray, scaleFactor=1.3, minNeighbors=5, minSize=(30, 30))

        for (x, y, w, h) in faces:
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

        photo = ImageTk.PhotoImage(image=Image.fromarray(frame))

        label.config(image=photo)
        label.image = photo

    root.after(10, update_frame)

root = tk.Tk()
root.title("Face Detection and ID")

width, height = 640, 480
root.geometry(f"{width}x{height}")

label = ttk.Label(root)
label.pack()

cap = cv2.VideoCapture(0)

if not cap.isOpened():
    raise Exception("Could not open camera.")

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

face_id_entry = ttk.Entry(root)
face_id_entry.pack()

add_button = ttk.Button(root, text="Add Face ID", command=add_face_id)
add_button.pack()

search_button = ttk.Button(root, text="Search", command=search_face)
search_button.pack()

ser = serial.Serial('COM6', 9600, timeout=1)
time.sleep(2)  

update_frame()

root.mainloop()

cap.release()
ser.close()
