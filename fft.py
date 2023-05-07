import time
import numpy as np
address = ('192.168.1.177', 5000)
data = [13,21,17,2,-4,67,83,-90,28,-21,5,39,-6]
s = socket(AF_INET, SOCK_DGRAM)
s.settimeout(1)
trans = np.fft.fft(data);
idx = 0
ready = -1
maxVal = max(abs(trans));

s.sendto(str(-1 * maxVal).encode(), address)

while(1):

    try:
        rec_data, addr = s.recvfrom(2048)
        if(int(rec_data) == ready):

            string = str(abs(trans[idx]))
            print(string)
            s.sendto(string.encode(), address)


            idx = idx + 1
            idx = idx % len(data)

        else:
             print(rec_data)
    except:
        print("No data")
        pass