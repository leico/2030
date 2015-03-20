#include <Servo.h>

Servo test;

int value;

void setup() {

  test.attach(8);
  // put your setup code here, to run once:

  value = 0;

}

void loop() {

  test.write(value);

  value = (value + 1) % 181;

  delay(300);
}
