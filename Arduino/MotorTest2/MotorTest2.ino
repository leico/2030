
const int OUT1 = 8;
const int OUT2 = 9;


int value;

void setup() {

  Serial.begin(9600);

  value = 0;
}

void loop() {

  if(Serial.available())
    value = Serial.read() % 255;

  analogWrite(OUT1, 0);
  analogWrite(OUT2, value);

  delay(500);

  analogWrite(OUT1, value);
  analogWrite(OUT2, 0);

  delay(400);

    
}
