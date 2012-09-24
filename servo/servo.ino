#include <Servo.h>

Servo myservo;
int pos = 0;    // variable to store the servo position 

int sensorPin = 0;	// light sensor is connected to analog pin 0
int sensorValue;	// variable to store the value coming from the sensor

void setup()
{
  myservo.attach(2);
  myservo.write(85);
  
   Serial.begin(9600);	//initialize the serial port
}

void loop() 
{ 
    sensorValue = analogRead(sensorPin);	// read the value from the sensor
    myservo.write(sensorValue/2);
    //Serial.println(sensorValue);	// send that value to the computer
    delay(100);	// delay for 1/10 of a second
  
  
  /*
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } */
}


