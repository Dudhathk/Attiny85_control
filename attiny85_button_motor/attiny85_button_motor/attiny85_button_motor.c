/*
 * attiny_85_blink_with_studio.c
 *
 * Created: 11/5/2022 4:52:54 PM
 *  Author: Hardik
 */ 

#include <avr/io.h>
#include <stdbool.h>

int main(void) {

  DDRB &= ~(1 << PB3);								//set PB3 as input
  PORTB |= (1 << PB3);								//activate pull-up resistor for PB3
  DDRB |= (1 << PB0);								//set PB4 as output
  DDRB |= (1 << PB1);
  PORTB |= 0b00000001;
  while(1)
  {
	  //read the button state
	  bool buttonState = PINB & (1 << PB3);
													//if the button is HIGH, turn led on
	  while(!buttonState) {
	   PORTB = PORTB ^ 0b00000001;					 //write to PORTB register to set the LED state to LOW
	   PORTB = PORTB ^ 0b00000010;
	   buttonState = PINB ^ (1 << PB3);
	  }
  }

}