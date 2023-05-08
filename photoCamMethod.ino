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


void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
  photoCam();
}

























void photoCam() {
  for(int i = 0; i < 16; i ++){
    digitalWrite(s0, (i & 1) >= 1);
    digitalWrite(s1, (i & 2) >= 1);
    digitalWrite(s2, (i & 4) >= 1);
    digitalWrite(s3, (i & 8) >= 1);
    value1 = analogRead(SIGL)/200;
    value2 = analogRead(SIGR)/200;

//    Serial.print("Slot C");
//    Serial.println(i);
//    Serial.print("Left Reads ");
//    Serial.println(SIGL);
//    Serial.print("Right Reads ");
//    Serial.println(SIGR);
    shifter = floor(i / 2) * 4;

    if (i%2 == 0) {
    matrix.fillRect(shifter , 24, 4,4, matrix.Color333(value1, value1, value1));
    matrix.fillRect(shifter+32 , 24, 4,4, matrix.Color333(value2, value2, value2));
    } 
    if (i%2 == 1) {
    matrix.fillRect(shifter , 28, 4, 4, matrix.Color333(value1, value1, value1));
    matrix.fillRect(shifter+32 , 28, 4, 4, matrix.Color333(value2, value2, value2));
    }
    
  }

  return;
}











