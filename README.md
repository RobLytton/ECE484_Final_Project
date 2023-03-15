# ECE484_Final_Project

Members - Rob Lytton, Alyssa Winn, John Dahlquist, and Teddy Lea

Our plan is to make a spectrum analyzer. 
This will preform the fourier transform and display the results to an array of LEDs.

Something similar to this project:
https://projecthub.arduino.cc/shajeeb/924af5cb-be01-44d6-888d-200c54188e9b
![image](https://user-images.githubusercontent.com/95442814/225405335-9c833da3-c541-4728-874f-bafeebf9d219.png)

![image](https://user-images.githubusercontent.com/95442814/225405623-d3ffba57-ff7c-4a81-aaff-b2ea86bff315.png)




We will use a python script to communicate over ethernet with the Arduino to send packets of the transform.

Parts:

Ethernet Module (W5500) - https://www.amazon.com/gp/product/B07MYY7QW2/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=misperry-20&creative=9325&linkCode=as2&creativeASIN=B07MYY7QW2&linkId=79ebbc9ffcb89f3e8ffc369f0427b16d

Led strips or matrix 

-----------------------------------------

If we get the base working in time we will add a photoresitor camera and act as a background 
https://petapixel.com/2019/05/20/i-built-a-kilopixel-camera-that-uses-a-single-photoresistor-for-portraits/

This kind of idea where the synthesizer is on top on a picture:
<img align="left" width="600" height="200" src= https://user-images.githubusercontent.com/95442814/225406496-231b97b7-3ce5-47a5-bd06-ada7c2e406a0.png>


Parts:

Photoresitor 
Motor
Disk
Possibly an anaolg shift register


