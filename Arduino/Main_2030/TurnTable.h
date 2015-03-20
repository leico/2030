#ifndef __TURN_TABLE_H__
#define __TURN_TABLE_H__
#include "Arduino.h"
#include <Metro.h>

class TurnTable{

  public:
  enum State{
      STOP
    , START
    , REVERSE
    , SCRATCH
  };

  private:
        unsigned char _power;
  const unsigned char _out1;
  const unsigned char _out2;

  bool _rotation;

  Metro _time;
  State _state;

  public:

  /* ======================================== *
   * Constructor                              *
   * ======================================== */
  TurnTable(unsigned char out1, unsigned char out2, unsigned char power, int time) :
  _out1(out1),
  _out2(out2),
  _power(power),
  _time  (time),
  _rotation(true),
  _state(STOP)
  {
    pinMode(_out1, OUTPUT);
    pinMode(_out2, OUTPUT);
  };

  /* ======================================== *
   * Constructor                              *
   * ======================================== */
  TurnTable() : 
  _out1(0),
  _out2(1),
  _power(255),
  _time(0),
  _rotation(true),
  _state(STOP)
  {
    pinMode(_out1, OUTPUT);
    pinMode(_out2, OUTPUT);
  };

  /* ======================================== *
   * Destructor                               *
   * ======================================== */
  virtual ~TurnTable(){};



  /* ======================================== *
   * void loop()                              *
   * ======================================== */
  void loop(){
    if(_time.check() != 1) return;
    switch(_state){
      case STOP    : Stop   (); break;
      case START   : Start  (); break;
      case REVERSE : Reverse(); break;
      case SCRATCH : Scratch(); break;
    }
  };

  /* ======================================== *
   * void Start()                             *
   * ======================================== */
  void Start(){
    analogWrite(_out1, _power);
    analogWrite(_out2, 0);
  };

  /* ======================================== *
   * void Reverse()                           *
   * ======================================== */
  void Reverse(){
    analogWrite(_out1, 0);
    analogWrite(_out2, _power);
  };
  
  /* ======================================== *
   * void Stop()                              *
   * ======================================== */
  void Stop(){
    analogWrite(_out1, 0);
    analogWrite(_out2, 0);
  };

  /* ======================================== *
   * void Scratch()                           *
   * ======================================== */
  void Scratch(){

    if(_rotation) Start();
    else         Reverse();

    _rotation = ! _rotation; 
  };

  /* ======================================== *
   * void ChangeState()                       *
   * ======================================== */
  void ChangeState(State state){

    _state = state;
  };

  /* ======================================== *
   * void ChangePower()                       *
   * ======================================== */
  void ChangePower(unsigned char power){
    _power = power;
  }
};

#endif
