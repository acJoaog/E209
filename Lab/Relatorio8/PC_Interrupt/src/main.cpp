#include <Arduino.h>

// Na interrupção PCINT0
ISR(PCINT0_vect)
{
  if(!(PINB & (1<<PB0))){
    PORTD |= (1<<PD7);
  _delay_ms(1000);
  PORTD &= ~(1<<PD7);
  }
  if(!(PINB & (1<<PB2))){
    PORTD |= (1<<PD6);
  _delay_ms(500);
  PORTD &= ~(1<<PD6);
  }
  
}

// Na interrupção PCINT1
ISR(PCINT1_vect)
{

}

// Na interrupção PCINT2
ISR(PCINT2_vect)
{
  PORTD |= (1<<PB1);
  _delay_ms(2000);
  PORTD &= ~(1<<PB1);
}

// PCINT0 -> PD7
// PCINT2 -> PD6
// PCINT20 -> PB1

int main(void)
{
  // Habilita interrupção no grupo PCINT2 e PCINT0
  PCICR |= 0b00000101;

  // Habilita PCINT no pino PD4 -> PCINT20
  PCMSK0 |= 0b00000101;
  PCMSK2 |= 0b00010000;

  DDRD |= (1 << PD5) | (1 << PD6) | (1 << PD7);
  DDRB |= (1 << PB1);

  PORTB |= (1<<PB0) | (1<<PB2);
  PORTD |= (1<<PD4);

  // Habilita Interrupções globais
  sei();

  for (;;)
  {
    PORTD ^= (1 << PD5);
    _delay_ms(250);
  }
}