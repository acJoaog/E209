#include <Arduino.h>

void main (void){

  DDRD |= (1<<PD6) | (1<<PD7);

  PORTD &= ~(0xC0);
}