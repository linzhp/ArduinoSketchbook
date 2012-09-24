#include <OrangutanLEDs.h>
#include <OrangutanAnalog.h>
#include <OrangutanMotors.h>
#include <Servo.h>

#define SERVO_MIN 80
#define SERVO_MIDDLE 100
#define SERVO_MAX 120
#define SERVO_INC 5
#define MOTOR_SPEED 128
#define SAMPLES 10
#define DELTA_COUNT 2

OrangutanAnalog analog;
OrangutanLEDs leds;
OrangutanMotors motors;

Servo myservo;

int rightLightSensorPin = 3;
int leftLightSensorPin = 1;

int rightLightVal = 0;
int leftLightVal = 0;
int LEDdelay = 0;
int lowval = 255;
int highval = 0;
int lightRange = 0;
int deflect = 0;
int lower_count = 0;
int greater_count = 0;

int servoval = 100;

void setup() {
  myservo.attach(2);
  myservo.write(SERVO_MIDDLE);
  analog.setMode(MODE_8_BIT);

  /*
    for (int i=0; i < 20; i++) {
    rightLightVal = analog.read(rightLightSensorPin);
    if (rightLightVal > highval) {
      highval = rightLightVal;
    }
    if (rightLightVal < lowval) {
      lowval = rightLightVal;
    }
    delay(125);
    leds.red(HIGH);
    delay(125);
    leds.red(LOW);
    
    delay(125);
    leds.red(HIGH);
    delay(125);
    leds.red(LOW);
  }
  
    lightRange = highval - lowval;
 */   
   blink_leds(2000);
   motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
  
}

void loop() {
  


  rightLightVal = analog.readAverage(rightLightSensorPin, SAMPLES);
  leftLightVal = analog.readAverage(leftLightSensorPin, SAMPLES);
  if(rightLightVal < leftLightVal)
  {
    lower_count = lower_count + 1;
    greater_count = 0;
    if (lower_count > DELTA_COUNT) {
      servoval = servoval - SERVO_INC;
      if (servoval < SERVO_MIN) servoval = SERVO_MIN;
    }
  } else{
    greater_count = greater_count + 1;
    lower_count = 0;
    if (greater_count > DELTA_COUNT) {
       servoval = servoval + SERVO_INC;
       if (servoval > SERVO_MAX) servoval = SERVO_MAX;
    }
  }
  
  deflect = (servoval - SERVO_MIDDLE)*3 ;

  myservo.write(servoval);
  
  
  
  motors.setSpeeds(clamp_256(MOTOR_SPEED-deflect),clamp_256(MOTOR_SPEED+deflect));
  
  blink_leds(25);
}

void blink_leds(int l_delay) {
    leds.red(HIGH);
  delay(l_delay);
  leds.red(LOW);
  delay(l_delay);
}
    
int clamp_256(int val) {
  int result = val;
  if (val < 0) result = 0;
  if (val > 255) result = 255;
  return result;
}
