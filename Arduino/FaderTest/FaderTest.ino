

//Min 287
//Max 774

const int OUT1 = 22;
const int OUT2 = 23;

const int TRACK = 0;

void setup() {

  Serial.begin(9600);

  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);

  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);

}

void loop() {

  if(Serial.available()){
    
    int value = Serial.read();

    switch(value){
      case 'a':
      {
        digitalWrite(OUT2, LOW);
        digitalWrite(OUT1, HIGH);
        delay(10);
        digitalWrite(OUT1, LOW);
        break;
      }
      case 'b':
      {
        digitalWrite(OUT1, LOW);
        digitalWrite(OUT2, HIGH);
        delay(10);
        digitalWrite(OUT2, LOW);
        break;
      }
    }

    int pos = analogRead(TRACK);
    Serial.write( highByte(pos) );
    Serial.write( lowByte (pos) );
  }

  delay(10);
}
