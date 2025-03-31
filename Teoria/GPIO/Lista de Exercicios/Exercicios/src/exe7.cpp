#include <Arduino.h>

void main (void){

  DDRD = 0b00001000;
  
  int estado = (PIND & 0b00000100);

  if (estado)
    PORTD |= 0b00001000;
  else
    PORTD &= ~(0b00001000);
}