
const int OUT1 = 8;
const int OUT2 = 9;

bool reverse;

int count;

void setup() {
  // put your setup code here, to run once:

  reverse = false;
  count   = 0;

}

void loop() {
  // put your main code here, to run repeatedly:

  if(reverse){
    analogWrite(OUT1, count);
    analogWrite(OUT2, 0);
  }
  else{
    analogWrite(OUT1, 0);
    analogWrite(OUT2, count);
  }

  count ++;
  if(count >= 255) reverse = ! reverse;
  
  count %= 255;

  delay(1000);

}
