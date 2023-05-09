import sys
f = open('data_in.sim', 'r')
from playsound import playsound
from socket import *
import time
from scipy.io import wavfile
import numpy as np
import os

address = ('192.168.1.177', 5000)
s = socket(AF_INET, SOCK_DGRAM)
s.settimeout(1)
print(sys.argv[1])
if(int(len(sys.argv)) == 2):
    songFile = str(sys.argv[1]) + '.wav'
else:
    songFile = str('rick.wav')

sampRate, song = wavfile.read(songFile)
idx = 0
readyNextPart = -1
readyNextBit = -2
perSec = 1
samps = int(np.floor(sampRate / perSec))
matrixLength = 64
sampAve = int(np.floor(samps / matrixLength))
firstString  = "Start"
sendIdx = 0
print("Sampling rate: " + str(sampRate))
print("Samps per update: " + str(samps))
print("Matrix Length: " + str(matrixLength))
print("Samps per column: " + str(sampAve))
print("Updating every 1/" + str(perSec) + " seconds" )
print("Playing song")

playsound(songFile, block = False)
s.sendto(firstString.encode(), address)
while idx < len(song):
    
        rec_data, addr = s.recvfrom(2048)
    
    
        if(int(rec_data) == int(readyNextPart)):
            
            tempData = song[idx * samps:idx * samps + samps];
            
            preFft = np.fft.fft(tempData);
            cut = (sampAve * matrixLength)
            
            
            tempCube = preFft[0:cut,0].reshape(matrixLength, sampAve);
            
            idx = idx + 1;
            tempFft = np.zeros(matrixLength)
            for i in range(matrixLength):
                tempFft[i] = np.mean(abs(tempCube[i,:]))
            
            

            fft = tempFft;
            
            sendMax = str(-1 * max((tempFft)))
            s.sendto(sendMax.encode(), address)

        elif(int(rec_data) ==  int(readyNextBit)):
            print("sending bit")
            sendVal = str(fft[sendIdx]);
            s.sendto(sendVal.encode(), address)
            sendIdx = sendIdx + 1;
            sendIdx = sendIdx % matrixLength

        else:
            send = "ERROR" 
            s.sendto(send.encode(), address)
    

        

