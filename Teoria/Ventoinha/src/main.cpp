#include <Arduino.h>

float velocidade = 0;

// função para alterar valor da variavel velocidade
void altera_vel(float porcentagem){
  velocidade = (porcentagem*255)/100;
}

int main(void){

  DDRD |= (1<<PD6); //definindo ventoinha no pino PD6

  PORTD |= (1 << PD2); //habilitando pull-up no pino PD2

  EICRA |= (1 << ISC01) | (1 << ISC00); //0b00000011 subida

  EIMSK |= (1 << INT0); //habilitando interrupção no PD2

  sei();

  PORTD &= ~(1 << PD6); //iniciando codigo com ventoinha desligado

  TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);

  TCCR0B = (1 << CS02) | (1 << CS00); // seleciona opção para frequência

  // aplica a velocidade alterada na interrupção
  for(;;){
    OCR0A = velocidade;
  }

}

// função de interrupção no pino PD2
ISR(INT0_vect){

  if(velocidade == 0){
    altera_vel(30);
  }else if (velocidade == (30*255)/100){
    altera_vel(60);
  }else if (velocidade == (60*255)/100){
    altera_vel(100);
  }else{
    altera_vel(0);
  }
  
  _delay_ms(50);
}