#include <Arduino.h>

void main (void){

  DDRD &= ~(1<<PD5);
  PORTD |= (1<<PD5);
  
}