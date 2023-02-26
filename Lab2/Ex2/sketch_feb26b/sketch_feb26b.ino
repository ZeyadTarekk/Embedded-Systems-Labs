#include<avr/io.h>
#include<avr/interrupt.h>

ISR(INT1_vect){

  for(int i=0;i<5;i++){
    PORTC = PORTC | (1<<PC1);
    PORTC = PORTC | (1<<PC2);
    PORTC = PORTC | (1<<PC3);
    _delay_ms(300);
    PORTC = PORTC & (~(1<<PC1));
    PORTC = PORTC & (~(1<<PC2));
    PORTC = PORTC & (~(1<<PC3));
    _delay_ms(300);
  }
}

void INT1_INIT(void){
  SREG &= ~(1<<7);
  DDRD &= (~(1<<PD3));
  EIMSK |= (1 << INT1);
  EICRA |= (1<<ISC10) | (1<<ISC11);
  SREG  |= (1<<7);
}

//void setup() {
//  // put your setup code here, to run once:
//
//}

int main(void) {
  // put your main code here, to run repeatedly:
  INT1_INIT();
  DDRC = DDRC | (1 << PC1);
//  PORTC = DDRC | (1<<PC1);

    DDRC = DDRC | (1 << PC2);
//  PORTC = DDRC | (1<<PC2);

    DDRC = DDRC | (1 << PC3);
//  PORTC = DDRC | (1<<PC3);

  while(1){
    
    PORTC = PORTC & (~(1<<PC2));
    PORTC = PORTC & (~(1<<PC3));
    PORTC = PORTC | (1<<PC1);
    
    _delay_ms(300);

    PORTC = PORTC & (~(1<<PC1));
    PORTC = PORTC & (~(1<<PC3));
    PORTC = PORTC | (1<<PC2);

     _delay_ms(300);

    PORTC = PORTC & (~(1<<PC1));
    PORTC = PORTC & (~(1<<PC2));
    PORTC = PORTC | (1<<PC3);

    _delay_ms(300);


    
  }
}
