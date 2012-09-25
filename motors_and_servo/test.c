#include <pololu/orangutan.h>
#include <avr/io.h>

/*
 * motors1: for the Orangutan LV, SV, SVP, X2, Baby-O and 3pi robot.
 *
 * This example uses the OrangutanMotors functions to drive
 * motors in response to the position of user trimmer potentiometer
 * and blinks the red user LED at a rate determined by the trimmer
 * potentiometer position.  It uses the OrangutanAnalog library to measure
 * the trimpot position, and it uses the OrangutanLEDs library to provide
 * limited feedback with the red user LED.
 *
 * http://www.pololu.com/docs/0J20
 * http://www.pololu.com
 * http://forum.pololu.com
 */

int main()
{
	int motorSpeed = 0;
  // Init servo on pin PD0
  servos_start((unsigned char[]){IO_D2}, 1);
  // Make servo go to neutral position
  set_servo_target(0, 1500);
 	motorSpeed = 150;
    set_motors(motorSpeed, motorSpeed);
    set_servo_speed(0,150);
    
  while(1)
  {
  	set_servo_target(0,1600);
  	delay_ms(3000);
  	set_servo_target(0,1500);
  	delay_ms(3000);
  	set_servo_target(0,1300);
  	delay_ms(3000);
  	set_servo_target(0,1500);
  	delay(3000);

  /*  int ledDelay = motorSpeed;
	if(ledDelay < 0)
	  ledDelay = -ledDelay;  // make the delay a non-negative number
	ledDelay = 256-ledDelay; // the delay should be short when the speed is high

    red_led(1);       // turn red LED on
    delay_ms(ledDelay);

    red_led(0);       // turn red LED off
	delay_ms(ledDelay);
	*/
	
	
  }
}
