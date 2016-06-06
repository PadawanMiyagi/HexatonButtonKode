import serial
import time
from firebase import firebase
firebase = firebase.FirebaseApplication('https://itpdp1.firebaseio.com',None)

lastSerial = ""

def run(ls):
    while 1:
        ser = serial.Serial('/dev/ttyUSB1', 9600,bytesize=serial.EIGHTBITS,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE, timeout=2)
        ser2 = str(ser.readline()) + ""
        time.sleep(1)
        print ser2
        if(ser2 != ls):
            firebase.delete('/tests/',"1")
            firebase.post('/tests/1',ser2)
            time.sleep(1)
            
        ls = ser2
        

run(lastSerial)}
