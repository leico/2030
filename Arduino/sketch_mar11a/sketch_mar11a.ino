
#include <Servo.h> 


Servo servo1;
int inByte;

void setup(){
 Serial.begin(9600);
 servo1.attach(2);
 servo1.write(0);
}

void loop(){
  if(Serial.available()){
    inByte = Serial.read();
    int value = inByte / 255.0 * 180;
    servo1.write( value );
    Serial.println(value);
  }
  delay(1000);
}

