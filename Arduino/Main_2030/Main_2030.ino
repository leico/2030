#include <Servo.h>
#include <Metro.h>
#include "TurnTable.h"
#include "Fader.h"

Servo left;
Servo center;
Servo right;

TurnTable L     (5, 6, 160, 200);
TurnTable R     (7, 8, 255, 400);
Fader     fader (9, 10, 0, 255, 100);

void fader_control(int arg1, int arg2);
void L_control    (int arg1, int arg2);
void R_control    (int arg1, int arg2);

void setup() {

  Serial.begin(9600);

  left  .attach(2);
  center.attach(3);
  right .attach(4);

  fader .ChangeState(Fader     :: STOP);
  L     .ChangeState(TurnTable :: STOP);
  R     .ChangeState(TurnTable :: STOP);
}

void loop() {

  if(Serial.available() >= 3){

    int type = Serial.read();
    int arg1 = Serial.read();
    int arg2 = Serial.read();

    switch(type){
      case 1: left  .write(arg1); break;
      case 2: center.write(arg1); break;
      case 3: right .write(arg1); break;

      case 4: L_control    (arg1, arg2); break;
      case 5: fader_control(arg1, arg2); break;
      case 6: R_control    (arg1, arg2); break;
    }
  }

  fader .loop();
  L     .loop();
  R     .loop();

  delay(30);
}



void fader_control(int arg1, int arg2){

  switch(arg1){
    case 2: fader.ChangePower(arg2); break;
    case 1: fader.ChangeState((Fader :: State)arg2); break;
  }

}

void L_control(int arg1, int arg2){

  switch(arg1){
    case 2: L.ChangePower(arg2); break;
    case 1: L.ChangeState((TurnTable :: State)arg2); break;
  }

}

void R_control(int arg1, int arg2){

  switch(arg1){
    case 2: R.ChangePower(arg2); break;
    case 1: R.ChangeState((TurnTable :: State)arg2); break;
  }

}
