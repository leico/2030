#include <Servo.h>

Servo left;
Servo center;
Servo right;

void setup() {
  
  Serial.begin(9600);
  
  left  .attach(2);
  center.attach(3);
  right .attach(4);
}

void loop() {


  if(Serial.available() >= 2){
    
    int pos   = Serial.read();
    int angle = Serial.read();

    switch(pos){
      case 2: left  .write(angle); break;
      case 3: center.write(angle); break;
      case 4: right .write(angle); break;
    }
  }

  delay(30);

}
