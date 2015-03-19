#include <Servo.h>
#include <Metro.h>
#include "TurnTable.h"
#include "Fader.h"

Servo left;
Servo center;
Servo right;

Fader     fader (9, 10, 0, 128, 100);
TurnTable L     (5, 6, 160, 200);
TurnTable R     (7, 8, 180, 400);

void fader_control(int arg1);
void L_control    (int arg1);
void R_control    (int arg1);

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

    switch(type){
      case 'a': left  .write(arg1); break;
      case 'b': center.write(arg1); break;
      case 'c': right .write(arg1); break;

      case 'f': fader_control(arg1); break;
      case 'l': L_control    (arg1); break;
      case 'r': R_control    (arg1); break;
    }
  }

  fader .loop();
  L     .loop();
  R     .loop();

  delay(30);
}



void fader_control(int arg1){
  int arg2 = Serial.read();

  switch(arg1){
    case 'p': fader.ChangePower(arg2); break;
    case 's': fader.ChangeState((Fader :: State)arg2); break;
  }
}

void L_control(int arg1){
  int arg2 = Serial.read();

  switch(arg1){
    case 'p': L.ChangePower(arg2); break;
    case 's': L.ChangeState((TurnTable :: State)arg2); break;
  }

}

void R_control(int arg1){
  int arg2 = Serial.read();

  switch(arg1){
    case 'p': R.ChangePower(arg2); break;
    case 's': R.ChangeState((TurnTable :: State)arg2); break;
  }

}
