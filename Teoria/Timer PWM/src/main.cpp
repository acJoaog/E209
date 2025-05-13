#include <Arduino.h>

//Variável de contagem global
unsigned int cont = 0;

int main(void){
  DDRD |= (1 << PD6);

  //Mode de operação CTC (Comparação)
  TCCR0A = (1<<WGM01);

  //Escolha do Pré - Scaler 8 -> 2MHz -> 500ns
  TCCR0B = (1<<CS01);

  //Habilitação da interrupção
  TIMSK0 = (1<<OCIE0A);

  //Definição do comparador
  OCR0A = 100; // 100 * 0,5us = 50us → ISR a cada 50us

  //Habilitar as interrupções globais
  sei();
}

ISR(TIMER0_COMPA_vect){

  cont++;
  if(cont <= 10){ //255ms high
    PORTD |= (1 << PD6);
  }
  else{           //255ms low
    PORTD &= ~(1 << PD6);
  }

  if (cont >= 20){
    cont = 0;
  }
}