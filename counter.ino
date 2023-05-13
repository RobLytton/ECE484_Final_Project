/*
* This is code we used to test the simplified code of the select singals 
* being sent to the shift registers
*/


void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  for(byte i = 0; i < 64; i++) {
 
    digitalWrite(13, i & 8);
    digitalWrite(12, i & 4);
    digitalWrite(11, i & 2);
    digitalWrite(10, i & 1);
    delay(150);
  }
  // ands with every single bit number
}
