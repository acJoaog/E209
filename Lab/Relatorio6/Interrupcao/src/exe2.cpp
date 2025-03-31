#include <Arduino.h>

int main(void){

  DDRD |= (1<<PD4) | (1<<PD5); //definindo leds nos pinos PD4 e PD5

  PORTD |= (1 << PD2) | (1 << PD3); //habilitando pull-up no pino PD2 e PD3

  EICRA |= (1 << ISC11) | (1 << ISC01) | (1 << ISC00); //0b00001011 subida INT0 / descida no INT1

  EIMSK |= (1<< INT1); //habilitando interrupção no PD3

  sei();

  for(;;){
    PORTD ^= (1<<PD5);
    _delay_ms(500);
  }
}

ISR(INT0_vect){
  PORTD |= (1<<PD4);
  _delay_ms(1000);
  PORTD &= ~(1<<PD4);
}

ISR(INT1_vect){
  EIMSK ^= (1 << INT0); //alternado interrupção no PD2
  _delay_ms(500);
}