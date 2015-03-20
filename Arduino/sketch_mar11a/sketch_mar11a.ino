
#include <Servo.h> 

const int FURU_COUNT = 3;
const int FURU_PIN   = 2;

const int MIN_FURU_PARAM = 0;
const int MAX_FURU_PARAM = 255;

const int DJ_COUNT = 3;
const int DJ_PIN   = FURU_PIN + FURU_COUNT + 1;

const int MIN_DJ_PARAM = 0;
const int MAX_DJ_PARAM = 255;


Servo furu[FURU_COUNT];
int inByte;

void setup(){
 Serial.begin(9600);

 for(int i = 0 ; i < FURU_COUNT ; ++ i){
   furu[i].attatch( FURU_PIN + i );
   furu[i].write(0);
 }

}

void loop(){

  if(Serial.available() > 2){

    int no    = Serial.read();
    int param = Serial.read();

    for(;;){
      if(no >= FURU_COUNT || no <  0){
        Serial.print(-1);
        break;
      }
      if(param < MIN_FURU_PARAM || param >= MAX_FURU_PARAM){
        Serial.print(-2);
        break;
      }

      int value = (param * 180.0) / MAX_FURU_PARAM;
      furu[ no ].write( value );
      delay(30);
      return;
    }

    no -= 10;

    if(no < 0 || no >= DJ_COUNT){
      Serial.print(-3);
      return;
    }
    
    if(param < MIN_DJ_PARAM || param >= MAX_DJ_PARAM){
      Serial.print(-4);
      return;
    }

    switch(no){
      case 0:{  //L Table
        break;
      }
      case 1:{  //Fader
        break;
      }
      case 2:{  //R Table
        break;
      }
    }

  }

}

