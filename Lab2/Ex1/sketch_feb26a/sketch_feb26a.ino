#include<avr/io.h>
#include<avr/interrupt.h>

ISR(INT0_vect){
  PORTC = PORTC ^ (1<<PC0);
}

void INT0_INIT(void){
  SREG &= ~(1<<7);
  DDRD &= (~(1<<PD2));
  EIMSK |= (1 << INT0);
  EICRA |= (1<<ISC00) | (1<<ISC01);
  SREG  |= (1<<7);
}

//void setup() {
//  // put your setup code here, to run once:
//
//}

int main(void) {
  // put your main code here, to run repeatedly:
  INT0_INIT();
  PORTC = DDRC | (1<<PC0);


  while(1){
    
  }
}
