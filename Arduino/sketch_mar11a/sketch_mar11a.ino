
#include <Servo.h> 


Servo servo1;
//const int LED1 = 3;
//const int LED2 = 5;

int pos = 0;
int FlgByte = 0;
int EffectByte = 0;

int inByte;

void setup(){
 Serial.begin(9600);
// pinMode(LED1, OUTPUT);
// pinMode(LED2, OUTPUT);
 servo1.attach(2);
 servo1.write(0);
}

void loop(){

//  analogWrite(LED1, 255);
//  analogWrite(LED2, 0);
//  delay(500);
//  analogWrite(LED1, 0);
//  analogWrite(LED2, 255);
//  delay(500);
//  Serial.println(Serial.read());
  if(Serial.available()){
    inByte = Serial.read();
    int value = inByte / 255.0 * 180;
    servo1.write( value );
    Serial.println(value);
  }
  delay(1000);
}
  
//  if (Serial.read() == 'a') {
//    FlgByte = 1;
//  } else if (Serial.read() == 'b') {
//    FlgByte = 2;
//  } else if (Serial.read() == 'c') {
//    FlgByte = 3;
//  }else {}
//  
//  
//  if (Serial.read() != 'a' ||Serial.read() == 'b' || Serial.read() == 'c') {
//    EffectByte = (int)Serial.read();
//  }
//    
//  if (FlgByte == 1){
//    analogWrite(LED1, EffectByte);
//    
//    analogWrite(LED2, 0);
//    
//  } else if (FlgByte == 2){
//    analogWrite(LED2, EffectByte);
//    
//    analogWrite(LED1, 0);
//    
//  } else if (FlgByte == 3){
//    servo1.write(EffectByte);
//    
//    analogWrite(LED1, 0);
//    analogWrite(LED2, 0);
//  }
//  
//  
//  Serial.println(FlgByte);
//  Serial.println(EffectByte);
//  
//  delay(500);
//  Serial.flush();
//  
//  FlgByte = Serial.read();
//  if (FlgByte ==1) {
//    EffectByte = Serial.read();
//    analogWrite(LED1, EffectByte);
//  } else if (FlgByte ==2){
//    EffectByte = Serial.read();
//    analogWrite(LED2, EffectByte);
//  } else if (FlgByte ==3){
//    EffectByte = Serial.read();
//    servo1.write(EffectByte);
//  }
  

  
//  Serial.println(EffectByte);
  
    // get incoming byte:
//    inByte = Serial.read();
//    servo1.write(inByte);
//    Serial.println(inByte); 
//    delay(15);
//}


