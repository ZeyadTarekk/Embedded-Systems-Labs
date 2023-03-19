#include <Arduino.h>

void adc_init()
{
  // AREF = AVcc
  ADMUX = (1 << REFS0);

  // ADC Enable and prescaler of 128
  // 16000000/128 = 125000
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t adc_read(uint8_t ch)
{
  // select the corresponding channel 0~5
  // ANDing with ’7′ will always keep the value
  // of ‘ch’ between 0 and 5
  ch &= 0b00000111;            // AND operation with 7
  ADMUX = (ADMUX & 0xF8) | ch; // clears the bottom 3 bits before ORing
  // start single conversion
  // write ’1′ to ADSC
  ADCSRA |= (1 << ADSC);
  // wait for conversion to complete
  // ADSC becomes ’0′ again
  // till then, run loop continuously
  while (ADCSRA & (1 << ADSC))
    ;

  return (ADC);
}

int main()
{
 DDRB |= (1 << PB0);
     DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
  Serial.begin(9600);
  // put your main code here, to run repeatedly:
  uint16_t adc_result0;
  // DDRB = 0x20; // to connect led to PB5
  int number;
  // initialize adc
  adc_init();
  // Serial.println("Started");
  while (1)
  {
    // Serial.println("Started");

    

    adc_result0 = adc_read(0); // read adc value at PC0
    // condition for led to turn on or off
    number = ((float)adc_result0) / 1024 * 8;

    Serial.println(number);
    PORTB =  number;
  }

  return 0;
}