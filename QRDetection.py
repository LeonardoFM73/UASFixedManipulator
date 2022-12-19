import cv2
from pyzbar import pyzbar
import subprocess
import time
import os

barcode_info=None
temp = 0
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
    global temp
    #C:\Users\dell\Downloads\UASFixedManipulato
    camera = cv2.VideoCapture(1,cv2.CAP_DSHOW)
    ret, frame = camera.read()
    print("Camera ON")
    while ret:
        ret, frame = camera.read()
        frame= read_barcodes(frame)
        #print(type(barcode_info))  
        if barcode_info == "Biru":
            rute=1
            if temp!=1:
                print("Warna Biru")
                os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track1.exe")
            #os.system('"C:/Users/dell/Downloads/UASFixedManipulator/Track1.exe"')
            barcode_info=None
            temp=rute
            #del result
            # print(barcode_info)
            # print(type(barcode_info))  
        elif barcode_info == "Merah":
            rute=2
            if temp!=2:
                print("Warna Merah")
                os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track2.exe")
            #os.system('"C:/Users/dell/Downloads/UASFixedManipulator/Track2.exe"')
            barcode_info=None
            temp=rute
            #del result
            # print(barcode_info)
            # print(type(barcode_info))
        elif barcode_info == "Hijau":
            rute=3
            if temp!=3:
                print("Warna Hijau")
                os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track3.exe")
            #os.system('"C:/Users/dell/Downloads/UASFixedManipulator/Track3.exe"')
            barcode_info=None
            temp=rute
            #del result
            # print(barcode_info)
            # print(type(barcode_info))
        elif barcode_info == "Kuning":
            rute=4
            if temp!=4:
                print("Warna Kuning")
                os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track4.exe")
            #os.system('"C:/Users/dell/Downloads/UASFixedManipulator/Track4.exe"')
            barcode_info=None
            temp=rute
            # print(barcode_info)
            # print(type(barcode_info))
        cv2.imshow('Barcode/QR code reader', frame)
        if cv2.waitKey(1) & 0xFF == 27:
            break
    #3
    camera.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    start_time = time.time()
    build()
    print("--- %s seconds ---" % (time.time() - start_time))
    #os.system("C:/Users/dell/Downloads/UASFixedManipulator/Track2.exe")
    main()