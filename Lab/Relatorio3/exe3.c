#include <avr/io.h>

#define E0 0
#define E1 1
#define E2 2

int main(){

  DDRD = 0b00000011;
  PORTD = 0b00000000;
  int estado = E2;

  for(;;){
    if(PIND & 0b00000100){
        switch(estado){
            case E0:
                PORTD = 0b00000001;
                estado = E1;
            break;

            case E1:
                PORTD = 0b00000010;
                estado = E2;
            break;

            case E2:
                PORTD = 0b00000000;
                estado = E0;
            break;

            default:
                PORTD = 0b00000000;
            break;
        }
        _delay_ms(1000);
    }
  }
}