#include <Arduino.h>

void main (void){

  DDRD |= (1<<PD3);
  DDRB |= (1<<PB4);

  PORTD ^= 0b00001000;
  PORTB ^= 0b00010000;
}