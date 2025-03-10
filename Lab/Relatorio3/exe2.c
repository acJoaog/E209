#define E0 0
#define E1 1
#define E2 2
#define E3 3

int main(){
    
    DDRD = 0b00000011;
    PORTD = 0b00000000;

    int estado = E0;

    for(;;){
        switch(estado){
            case E0:
                PORTD = 0b00000001;
                estado = E1;
                _delay_ms(500);
            break;
            
            case E1:
                PORTD = 0b00000010;
                estado = E2;
                _delay_ms(500);
            break;

            case E2:
                PORTD = 0b00000010;
                estado = E3;
                _delay_ms(500);
            break;

            case E3:
                PORTD = 0b00000011;
                estado = E0;
                _delay_ms(500);
            break;

            default:
                PORTD = 0b00000000;
            break;
        }
    }
}