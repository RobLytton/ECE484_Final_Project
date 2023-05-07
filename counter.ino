// WILL NOT FIT on ARDUINO UNO -- requires a Mega, M0 or M4 board
#include <RGBmatrixPanel.h>

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

//#define CLK  8   // USE THIS ON ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT  8

#define B   A1
#define C   A2
#define D   A3
RGBmatrixPanel matrix(A0, B, C, D, CLK, LAT, OE, false, 64);
void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  matrix.begin();
}
void loop() {
  for(byte i = 0; i < 64; i++) {
 
    digitalWrite(13, i & 8);
    digitalWrite(12, i & 4);
    digitalWrite(11, i & 2);
    digitalWrite(10, i & 1);
    delay(150);
    
    int diff = pow(2,9) / 64;
    uint16_t color = diff * i;
    
    matrix.drawLine(31, i,31,i, matrix.Color333(8,(i & 48) >> 3,i & 7));
  
    
  }
  
}
