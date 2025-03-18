#include <Arduino.h>

#define E0 0
#define E1 1
#define E2 2

int main(){

    DDRD |= 0b11000000; // Pino PD7 definido como saída
    //DDRD |= 0b01000000; // Pino PD6 definido como saída

    PORTD |= 0b00010000; // Habilitar PULL-UP no PD4

    PORTD &= ~(0b11000000); // Desliga a saída PD7
    //PORTD &= ~(0b01000000); // Desliga a saída PD6

    int estado = E2;
    

    for(;;){
        int botao = PIND & 0b00010000; // Lê o estado do PD4

        if(botao == 0){
            switch(estado){
                case E0:
                    PORTD |= 0b01000000;    // PD6 -> HIGH
                    PORTD &= ~(0b10000000); // PD7 -> LOW
                    estado = E1;
                break;

                case E1:
                    PORTD |= 0b10000000;    // PD7 -> HIGH
                    PORTD &= ~(0b01000000); // PD6 -> LOW
                    estado = E2;
                break;

                case E2:
                    PORTD &= ~(0b01000000); // PD6 -> LOW
                    PORTD &= ~(0b10000000); // PD7 -> LOW
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