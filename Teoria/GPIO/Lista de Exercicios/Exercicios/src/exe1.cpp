#include <Arduino.h>

void main (void){

  DDRD = 0b00000100;

  PORTD |= 0b00000100;
  
}