#include <Arduino.h>

//Variável de contagem global
unsigned int cont = 0;

int main(void){
  DDRD |= (1 << PD4);

  //Mode de operação CTC (Comparação)
  TCCR0A = (1<<WGM01);

  //Escolha do Pré - Scaler 8 -> 2MHz -> 500ns
  TCCR0B = (1<<CS01);

  //Habilitação da interrupção
  TIMSK0 = (1<<OCIE0A);

  //Definição do comparador
  OCR0A = 199; //100us //150ms -> cont == 1500

  //Habilitar as interrupções globais
  sei();
}

ISR(TIMER0_COMPA_vect){

  cont++;
  if(cont >= 1500){ //150ms
    PORTD ^= (1 << PD4);
    cont = 0;
  }

}