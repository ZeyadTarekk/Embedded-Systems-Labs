#include <avr/io.h>
#include <util/delay.h>
int toggle;

void setup() {
  // put your setup code here, to run once:
  DDRD = DDRD & (~(1<<PD4));

  DDRC = DDRC | (1<<PC0);
  DDRC = DDRC | (1<<PC1);
  DDRC = DDRC | (1<<PC2);
  DDRC = DDRC | (1<<PC3);

  PORTC = PORTC & ((1<<PC0));
  PORTC = PORTC & ((1<<PC1));
  PORTC = PORTC & ((1<<PC2));
  PORTC = PORTC & ((1<<PC3));
  
  toggle = 1;
}

void loop() {

  // put your main code here, to run repeatedly:
  
  
  if(!(PIND & (1<<PD4))){
    _delay_ms(30);
    if(!(PIND & (1<<PD0)) && toggle){
    //our logic
    
     toggle = 0;
    }
  } else {
    toggle = 1;
  }

    
  
}
