#include <Arduino.h>

int main(void)
{

  DDRD |= 0b10000000; // Pino PD7 definido como saída
  DDRD |= 0b01000000; // Pino PD6 definido como saída

  PORTD |= 0b00100000; // Habilitar PULL-UP no PD5
  PORTD |= 0b00010000; // Habilitar PULL-UP no PD4

  PORTD &= ~(0b10000000); // Desliga a saída PD7
  PORTD &= ~(0b01000000); // Desliga a saída PD6

  for (;;) // Super Loop
  {
    int botao1 = PIND & 0b00100000; // Lê o estado do PD5
    int botao2 = PIND & 0b00010000; // Lê o estado do PD5

    if (botao1 == 0) // Botão está pressionado ?
    {
      PORTD |= 0b10000000; // PD7 -> HIGH
      _delay_ms(1000); // Espera 5s
      PORTD &= ~(0b10000000); // PD7 -> LOW
    }

    if (botao2 == 0) // Botão está pressionado ?
    {
      PORTD |= 0b01000000; // PD7 -> HIGH
      _delay_ms(1000); // Espera 5s
      PORTD &= ~(0b01000000); // PD7 -> LOW
    }
  }
}