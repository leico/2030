
#ifndef __FADER_H__
#define __FADER_H__


#include "Arduino.h"
#include <Metro.h>

class Fader{

  public:
    enum State{
      LEFT,
      RIGHT,
      STOP
    };

  private:
  const static int MIN = 287;
  const static int MAX = 774;

  const unsigned char _out1;
  const unsigned char _out2;
  const unsigned char _statepin;

  unsigned char _power;
           int  _pos;

  Metro _time;
  State _state;

  public:

  /* ======================================== *
   * Constructor                              *
   * ======================================== */
  Fader() : 
  _out1(0),
  _out2(1),
  _statepin(0),
  _time(10),
  _power(255),
  _pos( analogRead(_statepin) )
  {
    pinMode(_out1, OUTPUT);
    pinMode(_out2, OUTPUT);
  };

  /* ======================================== *
   * Constructor                              *
   * ======================================== */
  Fader(unsigned char out1, unsigned char out2, unsigned char statepin, unsigned char power, int time) : 
  _out1(out1),
  _out2(out2),
  _statepin(statepin),
  _power(power),
  _time(time),
  _pos( analogRead(_statepin) )
  {
    pinMode(_out1, OUTPUT);
    pinMode(_out2, OUTPUT);
  };

  /* ======================================== *
   * Destructor                               *
   * ======================================== */
  virtual ~Fader(){};


  /* ======================================== *
   * void loop()                              *
   * ======================================== */
  void loop(){

    _pos = analogRead(_statepin);

    if(_time.check() != 1) return;

    switch(_state){
      case STOP  : Stop(); break;
      case LEFT  : Left(); break;
      case RIGHT : Right(); break;
    }
  };

  /* ======================================== *
   * void Left()                              *
   * ======================================== */
  void Left(){
    
    if(_pos == MIN){
      ChangeState(STOP);
      return;
    }

    analogWrite(_out1, _power);
    analogWrite(_out2, LOW);

    delay(1);

    Stop();
  };

  /* ======================================== *
   * void Right()                             *
   * ======================================== */
   void Right(){
    
    if(_pos == MAX){
      ChangeState(STOP);
      return;
    }

    analogWrite(_out1, LOW);
    analogWrite(_out2, _power);

    delay(1);

    Stop();
  };

  /* ======================================== *
   * void Stop()                              *
   * ======================================== */
  void Stop(){
    digitalWrite(_out1, LOW);
    digitalWrite(_out2, LOW);
  }

  /* ======================================== *
   * void ChangeState()                       *
   * ======================================== */
  void ChangeState(State state){
    _state = state;
  }

  /* ======================================== *
   * void ChangePower()                        *
   * ======================================== */
  void ChangePower(unsigned char power){
    _power = power;
  }
  

};

#endif
