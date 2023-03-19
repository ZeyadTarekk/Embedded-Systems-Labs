#include <avr/io.h>
#include <util/delay.h>

void SPI_Init()
{
  DDRB &= ~(1 << PB2);
  DDRB &= ~(1 << PB3);
  DDRB &= ~(1 << PB5);
  DDRB |= (1 << PB4);
  SPCR |= (1 << SPE);
}

void SPI_Write(char data)
{

  char flush_buffer;
  SPDR = data; // Write data to buffer
  while (!(SPSR & (1 << SPIF)))
    ; // Wait till transmission is complete
  flush_buffer = SPDR;
}

char SPI_Recieve()
{
  while (!(SPSR & (1 << SPIF)))
    ;
  return (SPDR);
}

void setup()
{
  SPI_Init();

  Serial.begin(9600);
  delay(100);
  Serial.println("Entered Slave");
}

uint8_t count;

void loop()
{
  count = SPI_Recieve();
  Serial.println(count);
  _delay_ms(1000);
  count = count + 100;
  SPI_Write(count);
  _delay_ms(1000);
}