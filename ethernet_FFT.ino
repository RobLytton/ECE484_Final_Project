/*
 * Code used to send FFT data through ethernet 
 * and outputs it to and LED matrix
 * 
 */
#include <Ethernet.h> //Load Ethernet Library
#include <EthernetUdp.h> //Load the Udp Library
#include <SPI.h> //Load SPI Library


#include <RGBmatrixPanel.h>

#define CLK 11 
#define OE   9
#define LAT  8
#define A   A0
#define B   A1
#define C   A2
#define D   A3
int value = 0;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

byte mac[] ={ 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE}; //Assign mac address
IPAddress ip(192,168,1,177); //Assign the IP Adress
unsigned int localPort = 5000; // Assign a port to talk over
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //dimensian a char array to hold our data packet
String datReq; //String for our data
int packetSize; //Size of the packet
EthernetUDP Udp; // Create a UDP Object
int maxVal;
int idx = 0;


void setup() {
  matrix.begin();
  Serial.begin(9600); //Initialize Serial Port 
  Ethernet.begin(mac, ip); //Inialize the Ethernet
  Udp.begin(localPort); //Initialize Udp
  delay(1500); //delay
  matrix.fillScreen(0); // sets screen to black

}



void loop() {
  
  
  packetSize = Udp.parsePacket(); 
  
  if(packetSize>0) { // if packetSize is >0, that means someone has sent a request
    
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE); //Read the data request
    
    int data = atoi(packetBuffer); //Convert char array packetBuffer into a int for the data
    
    if(data > 0) {
      int height = (((data * 32) / maxVal) % 32); // normalize the height of the column
      int diff = pow(2,9) / 64;
      int color = diff * idx;
      
      matrix.drawLine(idx, 31,idx, 0, matrix.Color333(0,0,0)); // draws black over the previous line
    //matrix.Color333(2*idx %7 +1,0,idx%7 +1)
      matrix.drawLine(idx, 31,idx, 31 - height, color); // rewrites 
      
      idx++; // moves to next column
      idx %= 64; // resets to the front of it 
      
    } else {
      maxVal = -1 * data; // gets the max height of the fft 
      
    }
    delay(150);
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort()); 
    Udp.print(-1); // sends ready signal back to master
    Udp.endPacket();
  } 
  memset(packetBuffer, 0, UDP_TX_PACKET_MAX_SIZE); //clear out the packetBuffer array
}
