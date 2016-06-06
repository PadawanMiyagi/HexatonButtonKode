{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf130
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 import serial\
import time\
from firebase import firebase\
firebase = firebase.FirebaseApplication('https://itpdp1.firebaseio.com',None)\
\
lastSerial = ""\
\
def run(ls):\
    while 1:\
        ser = serial.Serial('/dev/ttyUSB1', 9600,bytesize=serial.EIGHTBITS,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE, timeout=2)\
        ser2 = str(ser.readline()) + ""\
        time.sleep(1)\
        print ser2\
        if(ser2 != ls):\
            firebase.delete('/tests/',"1")\
            firebase.post('/tests/1',ser2)\
            time.sleep(1)\
            \
        ls = ser2\
        \
\
run(lastSerial)}