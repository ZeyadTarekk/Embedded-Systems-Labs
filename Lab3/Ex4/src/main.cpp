#include <avr/io.h>
#include <avr/interrupt.h>
// initialize timer, interrupt and variable
void timer1_init()
{
  TCNT2 = 0;
  OCR2A = 250;

  DDRB |= 8;

  // non PWM
  TCCR2B |= (1 << 7);

  // CTC mode
  TCCR2B &= ~8;
  TCCR2A |= 2;
  TCCR2A &= ~1;

  // toggle OC2A
  TCCR2A |= (1 << 6);
  TCCR2A &= ~(1 << 7);

  // setting clock/1024
  TCCR2B |= 7;
}
int main()
{
  // connect led to pin PB1
  // DDRB |= (1 << PB0);
  // DDRD |= (1 << PD5);
  // initialize timer
  timer1_init();
  while (1)
  {
    // do nothing
    // whenever a match occurs
    // OC1A is toggled automatically!
    // no need to keep track of any flag bits or ISR
  }
  return 0;
}