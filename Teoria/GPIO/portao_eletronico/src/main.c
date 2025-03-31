
#include <stdio.h>
#include <avr/io.h>

#define set_bit(Y,bit_x) (Y|=(1<<bit_x))
#define clr_bit(Y,bit_x) (Y&=~(1<<bit_x))
#define tst_bit(Y,bit_x) (Y&(1<<bit_x))

#define MOTOR_ABERTO   0
#define MOTOR_FECHADO  1
#define MOTOR_FECHANDO 2
#define MOTOR_ABRINDO  3

void main (void)
{
  DDRD = 0b00000011;
  PORTD = 0b00000000;

  char MF = 0; //bit 0
  char MA = 1; //bit 1
  char SF = 2; //bit 2
  char SA = 3; //bit 3
  char CF = 4; //bit 4
  char CA = 5; //bit 5

  char estado = 0;

  for(;;){
    switch (estado)
    {
      case MOTOR_ABERTO:
        clr_bit(PORTD,MF); //MF = 0;
        clr_bit(PORTD,MA); //MA = 0;
        
        if(tst_bit(PIND,CF))
          estado = MOTOR_FECHANDO;
      break;
      
      case MOTOR_FECHADO:
        clr_bit(PORTD,MF); //MF = 0;
        clr_bit(PORTD,MA); //MA = 0;
        
        if(tst_bit(PIND,CA))
          estado = MOTOR_ABRINDO;
      break;

      case MOTOR_FECHANDO:
        set_bit(PORTD,MF); //MF = 1;
        clr_bit(PORTD,MA); //MA = 0;
        
        if (tst_bit(PIND,SF))
          estado = MOTOR_FECHADO;
      break;

      case MOTOR_ABRINDO:
        clr_bit(PORTD,MF); //MF = 0;
        set_bit(PORTD,MA); //MA = 1;
        
        if(tst_bit(PIND,SA))
          estado = MOTOR_ABERTO;
      break;

      default:
      break;
    }
  }
}