#define E0 0
#define E1 1
#define E2 2
#define E3 3
#define OFF -1

int main(){

  DDRD = 0b00000111;
  PORTD = 0b00000001;
  int estado = E0;

  for(;;){
    if(PIND & 0b00001000){
        switch(estado){
            case E0:
            PORTD = 0b00000001;
            _delay_ms(500);
            estado = E1;
            break;

            case E1:
            PORTD = 0b00000010;
            _delay_ms(500);
            estado = E2;
            break;

            case E2:
            PORTD = 0b00000000;
            _delay_ms(500);
            estado = ;
            break;

            default:
            PORTD = 0b00000000;
            break;
        }
    }
  }
}