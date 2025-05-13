#include <Arduino.h>

int brilho = 0;

int main(void){

  DDRD |= (1<<PD6); //definindo led no pino PD6

  PORTD |= (1 << PD2); //habilitando pull-up no pino PD2

  EICRA |= (1 << ISC01) | (1 << ISC00); //0b00000011 subida

  EIMSK |= (1 << INT0); //habilitando interrupção no PD2

  sei();

  PORTD &= ~(1 << PD6); //iniciando codigo com led desligado

  TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);

  TCCR0B = (1 << CS02) | (1 << CS00); // Seleciona opção para frequência

  OCR0A = 0;

  for(;;){
    OCR0A = brilho;
  }

}ISR(INT0_vect){

  brilho += (10 * 255)/100;

  if(brilho >= 256){
    brilho = 0;
  }
  
  _delay_ms(50);
}