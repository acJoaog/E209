#include <Arduino.h>

//Variável de contagem global
unsigned int cont1 = 0;
unsigned int cont2 = 0;

int main(void){
  DDRD |= (1 << PD4) | (1 << PD5);
  PORTD &= ~(1 << PD4) | ~(1 << PD5);

  //Mode de operação CTC (Comparação)
  TCCR0A = (1<<WGM01);

  //Escolha do Pré - Scaler 8 -> 2MHz -> 500ns
  TCCR0B = (1<<CS01);

  //Habilitação da interrupção
  TIMSK0 = (1<<OCIE0A);

  //Definição do comparador
  OCR0A = 199; //100us //1000ms(1s) -> cont == 1500

  //Habilitar as interrupções globais
  sei();

  for(;;){

  }
}

ISR(TIMER0_COMPA_vect){

  cont1++;
  if(cont1 >= 10000){ //1s
    PORTD |= (1 << PD4);
    
    if(cont1 >= 11000){ // 1s + 100ms
      PORTD &= ~(1 << PD4);
      cont1 = 1000;
    }
  }

  cont2++;
  if(cont2 >= 50000){ //60s
    PORTD |= (1 << PD5);
    if(cont2 >= 51000){ // 60s + 100 ms
      PORTD &= ~(1 << PD5);
      cont2 = 1000;
    }
  }

}