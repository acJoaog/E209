#include <Arduino.h>

int main(void){

  DDRD |= (1<<PD4) | (1<<PD5); //definindo leds nos pinos PD4 e PD5

  PORTD |= (1 << PD2); //habilitando pull-up no pino PD2

  EICRA |= (1 << ISC01) | (1 << ISC00); //0b00000011 subida

  EIMSK |= (1 << INT0); //habilitando interrupção no PD2

  sei();

  for(;;){
    PORTD ^= (1<<PD5);
    _delay_ms(500);
  }

}ISR(INT0_vect){
  PORTD |= (1<<PD4);
  _delay_ms(1000);
  PORTD &= ~(1<<PD4);
}
