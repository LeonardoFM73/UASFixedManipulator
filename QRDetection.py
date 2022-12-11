import cv2
from pyzbar import pyzbar
import subprocess
import time
import os

barcode_info=None

def read_barcodes(frame):
    global barcode_info
    barcodes = pyzbar.decode(frame)
    for barcode in barcodes:
        x, y , w, h = barcode.rect
    
        barcode_info = barcode.data.decode('utf-8')
        cv2.rectangle(frame, (x, y),(x+w, y+h), (0, 255, 0), 2)
        
        #2
        font = cv2.FONT_HERSHEY_DUPLEX
        cv2.putText(frame, barcode_info, (x + 6, y - 6), font, 2.0, (255, 255, 255), 1)
        


    return frame

def build():
    os.chdir("C:/Program Files (x86)/Dev-Cpp/MinGW64/bin")
    os.system("g++ C:/Users/dell/Downloads/UASFixedManipulator/Track1.cpp -o C:/Users/dell/Downloads/UASFixedManipulator/Track1.exe")
    os.system("g++ C:/Users/dell/Downloads/UASFixedManipulator/Track2.cpp -o C:/Users/dell/Downloads/UASFixedManipulator/Track2.exe")
    os.system("g++ C:/Users/dell/Downloads/UASFixedManipulator/Track3.cpp -o C:/Users/dell/Downloads/UASFixedManipulator/Track3.exe")
    os.system("g++ C:/Users/dell/Downloads/UASFixedManipulator/Track4.cpp -o C:/Users/dell/Downloads/UASFixedManipulator/Track4.exe")

    

def main():
    global barcode_info
    #C:\Users\dell\Downloads\UASFixedManipulato
    camera = cv2.VideoCapture(0)
    ret, frame = camera.read()
    while ret:
        ret, frame = camera.read()
        frame= read_barcodes(frame)
        #print(type(barcode_info))  
        if barcode_info == "Biru":
            print("Warna Biru")
            os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track1.exe")
            #os.system('"C:/Users/dell/Downloads/UASFixedManipulator/Track1.exe"')
            barcode_info=None
            #del result
            # print(barcode_info)
            # print(type(barcode_info))  
            time.sleep(5)
        elif barcode_info == "Merah":
            print("Warna Merah")
            os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track2.exe")
            #os.system('"C:/Users/dell/Downloads/UASFixedManipulator/Track2.exe"')
            barcode_info=None
            #del result
            # print(barcode_info)
            # print(type(barcode_info))
            time.sleep(5)
        elif barcode_info == "Hijau":
            print("Warna Hijau")
            os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track3.exe")
            #os.system('"C:/Users/dell/Downloads/UASFixedManipulator/Track3.exe"')
            barcode_info=None
            #del result
            # print(barcode_info)
            # print(type(barcode_info))
            time.sleep(5)
        elif barcode_info == "Kuning":
            print("Warna Kuning")
            os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track4.exe")
            #os.system('"C:/Users/dell/Downloads/UASFixedManipulator/Track4.exe"')
            barcode_info=None
            # print(barcode_info)
            # print(type(barcode_info))
            time.sleep(5)
        cv2.imshow('Barcode/QR code reader', frame)
        if cv2.waitKey(1) & 0xFF == 27:
            break
    #3
    camera.release()
    cv2.destroyAllWindows()
4
if __name__ == '__main__':
    build()
    #os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track2.exe")
    main()