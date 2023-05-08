#include <RGBmatrixPanel.h>


#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT  8
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

//Mux control pins
int s0 = 40;
int s1 = 41;
int s2 = 42;
int s3 = 43;

//Mux in "SIG" pin
int SIGL = A9;
int SIGR = A8;
int count;
int value1;
int value2;
int shifter;

void setup(){
  matrix.begin();
  matrix.fillScreen(matrix.Color333(5, 5, 5));
  delay(200);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  
  Serial.begin(9600);
}

void loop() {


  for(int i = 0; i < 16; i ++){
    int left = analogRead(SIGL);
    int right = analogRead(SIGR);
    digitalWrite(s0, (i & 1) >= 1);
    digitalWrite(s1, (i & 2) >= 1);
    digitalWrite(s2, (i & 4) >= 1);
    digitalWrite(s3, (i & 8) >= 1);
    Serial.print("Slot C");
    Serial.println(i);
    Serial.print("Left Reads ");
    Serial.println(left);
    Serial.print("Right Reads ");
    Serial.println(right);
    value1 = analogRead(SIGL)/200;
    value2 = analogRead(SIGR)/200;
    if (i == 0 || i == 1) {
      shifter = 0;
    }
    if (i == 2 || i == 3) {
      shifter = 4;
    }
    if (i == 4 || i == 5) {
      shifter = 8;
    }
    if (i == 6 || i == 7) {
      shifter = 12;
    }
    if (i == 8 || i == 9) {
      shifter = 16;
    }
    if (i == 10 || i == 11) {
      shifter = 20;
    }
    if (i == 12 || i == 13) {
      shifter = 24;
    }
    if (i == 14 || i == 15) {
      shifter = 28;
    }
    
    if (i%2 == 0) {
    matrix.fillRect(shifter , 24, 4,4, matrix.Color333(value1, value1, value1));
    matrix.fillRect(shifter+31 , 24, 4,4, matrix.Color333(value2, value2, value2));
    } 
    if (i%2 == 1) {
    matrix.fillRect(shifter , 28, 4, 4, matrix.Color333(value1, value1, value1));
    matrix.fillRect(shifter+31 , 28, 4, 4, matrix.Color333(value2, value2, value2));
    }

    
//    Serial.println(value);
//    Serial.print("Right Reads ");
//    value = analogRead(SIGR)/100;
//    matrix.fillRect(0, 0, 10, 10, matrix.Color333(value, value, value));
    
    
//    Serial.println(value);
    //delay(250);
  // <300 low
  // >300 < 600 medium
  // >600 high
    
  }
  //matrix.fillScreen(matrix.Color333(0, 0, 0));
//delay(5000);
}
