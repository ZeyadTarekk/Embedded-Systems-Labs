#include <Arduino.h>
#include <avr/io.h>

// global variable to count the number of overflows
volatile uint8_t tot_overflow;
// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER2_OVF_vect)
{
  // keep a track of number of overflows
  tot_overflow++;
}

void timer2_init()
{
  TCCR2B |= ((1 << CS22) | (1 << CS20) | (1 << CS21));
  // initialize counter
  TCNT2 = 0;
  // enable overflow interrupt
  TIMSK2 |= (1 << TOIE2);
  // enable global interrupts
  sei();
}
int main()
{
  Serial.begin(9600);
  // connect led to pin PC0
  DDRC |= (1 << PC0);
  // initialize timer
  timer2_init();
  // loop forever
  while (1)
  {
    // check if no. of overflows = 30
    if (tot_overflow >= 30) // NOTE: '>=' is used
    {
      Serial.println("Enetered FIRST IF CONDITION");
      // check if the timer count reaches 131
      if (TCNT2 >= 131)
      {
        Serial.println("Enetered second");
        PORTC ^= (1 << PC0); // toggles the led
        TCNT2 = 0;           // reset counter
        tot_overflow = 0;    // reset overflow counter
      }
    }
  }
  return 0;
}