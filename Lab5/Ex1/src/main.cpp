
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include<Arduino.h>

// SPI Intialzation for The master
void SPI_init()
{
  // Make PB3,PB5,PB2 as Output
  DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2);
  DDRB &= ~(1 << PB4);
  PORTB |= (1 << PB2);
  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
  SPSR &= ~(1 << SPI2X);
}

// Master Sends Data
void SPI_Write(char data)
{

  char flush_buffer;
  SPDR = data; // Write data to buffer
  while (!(SPSR & (1 << SPIF)))
    ; // Wait till transmission is complete
  flush_buffer = SPDR;
}

// Master Reads Data
char SPI_Read()
{
  SPDR = 0xFF;
  while (!(SPSR & (1 << SPIF)))
    ;
  return (SPDR);
}

void setup()
{
  Serial.begin(9600);
  SPI_init();
  PORTB &= ~(1 << PB2);
  _delay_ms(1000);
}

uint8_t count = 1;
uint8_t a;
void loop()
{
  count++;
  if (count > 100)
  {
    count = 1;
  }
  SPI_Write(count);
  _delay_ms(1000);
  a = SPI_Read();
  Serial.println(a);
  _delay_ms(1000);
}