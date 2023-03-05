#include <Arduino.h>
#include <avr/io.h>

// global variable to count the number of overflows
volatile uint8_t tot_overflow;
int currentNum = 0;
// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER2_OVF_vect)
{
  // keep a track of number of overflows
  tot_overflow++;
}

int convertNumber(int num)
{
  if(num == 0)
    return 0x3F;
  else if(num == 1)
    return 0x6;
  else if(num == 2)
    return 0x5B;
  else if(num == 3)
    return 0x4F;
  else if(num == 4)
    return 0x66;
  else if(num == 5)
    return 0x6D;
  else if(num == 6)
    return 0x7D;
  else if(num == 7)
    return 0x7;
  else if(num == 8)
    return 0x7F;
  else if(num == 9)
    return 0x6F;

}

void timer2_init()
{
  TCCR2B |= ((1 << CS22) | (1 << CS21));
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
  DDRC |= 0xFF;
  // initialize timer
  timer2_init();
  // loop forever
  while (1)
  {
    // check if no. of overflows = 30
    if (tot_overflow >= 244) // NOTE: '>=' is used
    {
      Serial.println("Enetered FIRST IF CONDITION");
      // check if the timer count reaches 131
      if (TCNT2 >= 36)
      {
        if (currentNum == 9)
        {
          currentNum = 0;
        }
        else
        {
          currentNum++;
        }
        PORTC = convertNumber(currentNum);

        
        TCNT2 = 0;        // reset counter
        tot_overflow = 0; // reset overflow counter
      }
    }
  }
  return 0;
}