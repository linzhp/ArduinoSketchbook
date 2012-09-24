/*
Control the motor according to the truth table at:
http://www.pololu.com/docs/0J14/all#9
*/

/* 
map aduino pin number to Baby Orangutan
pin names, according to
http://www.pololu.com/docs/0J17/2.b
*/
int pd5 = 5;
int pd6 = 6;
int pd3 = 3;
int pb3 = 11;

void setup()
{
  pinMode(pd5, OUTPUT);
  pinMode(pd6, OUTPUT);
  pinMode(pd3, OUTPUT);
  pinMode(pb3, OUTPUT);
  
  digitalWrite(pd5, HIGH);
  digitalWrite(pd3, HIGH);
  digitalWrite(pb3, LOW);
  digitalWrite(pd6, LOW);
}
  
void loop()
{
}
