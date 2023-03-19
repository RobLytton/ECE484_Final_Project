# ECE484_Final_Project

Members - Rob Lytton, Alyssa Winn, John Dahlquist, and Teddy Lea

Our plan is to make a spectrum analyzer. 
This will preform the fourier transform and display the results to an array of LEDs.  We are planning for these LEDs to be multicolored from one end of the spectrum to the other to represent the different frequencies.

Something similar to this project:
https://projecthub.arduino.cc/shajeeb/924af5cb-be01-44d6-888d-200c54188e9b
<p align="center">
  <img width="600" height="400" src= https://user-images.githubusercontent.com/95442814/225405335-9c833da3-c541-4728-874f-bafeebf9d219.png>
</p>
  
<p align="center">
  <img width="600" height="300" src= https://user-images.githubusercontent.com/95442814/225405623-d3ffba57-ff7c-4a81-aaff-b2ea86bff315.png>
</p>

<p align="center">
  <img width="600" height="300" src= https://https://i.imgur.com/GPvFUbU.jpg>
</p>



We will use a python script to communicate over ethernet with the Arduino to send packets of the transform.

Parts:

Ethernet Module (W5500): https://www.amazon.com/gp/product/B07MYY7QW2/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=misperry-20&creative=9325&linkCode=as2&creativeASIN=B07MYY7QW2&linkId=79ebbc9ffcb89f3e8ffc369f0427b16d

Led Strips (WS2812B): https://www.amazon.com/dp/B01MG49QKD?psc=1&ref=ppx_yo2ov_dt_b_product_details

OR LED Matrix (Adafruit): (Square, 607):
                           https://www.adafruit.com/product/607?gclid=Cj0KCQjw2cWgBhDYARIsALggUhohS2UZLo8eeu252DALdVTg090HjBv7XJ6a4XWzCzEilPn6AEBO9f4aAurgEALw_wcB
                           (Rectangle, 420): https://www.adafruit.com/product/420

-----------------------------------------

If we get the base working in time we will add a photoresitor camera and act as a background.  The idea behind this one is that we would have a the scanned picture behind the spectrum analyzer showing both the analysis going on and the image behind it. 
https://petapixel.com/2019/05/20/i-built-a-kilopixel-camera-that-uses-a-single-photoresistor-for-portraits/

This kind of idea where the synthesizer is on top on a picture:
<p align="center">
  <img width="600" height="200" src= https://user-images.githubusercontent.com/95442814/225406496-231b97b7-3ce5-47a5-bd06-ada7c2e406a0.png>
</p>

Parts:

Photoresitor 
Motor
Disk
Possibly an anaolg shift register


