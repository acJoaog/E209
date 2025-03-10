#define VD 0
#define AM 1
#define VM 2
#define OFF -1

int main(){

  DDRD = 0b00000111;
  PORTD = 0b00000000;
  int est_atual = OFF;

  for(;;){

    if(PIND & 0b00001000){
      est_atual = VD;
    }

    switch(est_atual){

      case VD:
        PORTD = 0b00000001;
        _delay_ms(8000);
        est_atual = AM;
        break;

      case AM:
        PORTD = 0b00000010;
        _delay_ms(2000);
        est_atual = VM;
        break;

      case VM:
        PORTD = 0b00000100;
        _delay_ms(10000);
        est_atual = OFF;
        break;

      default:
        PORTD = 0b00000000;
        break;
    }

  }

}