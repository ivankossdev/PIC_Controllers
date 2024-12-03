#include "spi.h"
#define cs RA5

/**************
 * pic 16f876 *
 * RA5-> CS   *
 * RC3-> CLK  *
 * RC5-> DIN  *
 **************/
void spi_init() {
    
    TRISC |= 0x10;  // miso in
    TRISC &= ~0x28; // mosi sck out
    TRISA &= ~0x20; // SS out
    PORTA &= ~0x20; 
    SSPCON = 0x30;  // SSPEN=1 SKP=1 SSPM0=0 SSPM1=0 SSPM2=0 SSPM3=0
    SSPSTAT = 0x80; // SMP=1;
}

void send_byte_spi(char data) {
    SSPBUF = data;
    while (!SSPIF);
    SSPIF = 0;
}

void send_spi(char rg, char dt) {
    cs = 0;
    send_byte_spi(rg);
    send_byte_spi(dt);
    cs = 1;
}
void clrf (void)
{
  char i=8;
  do
  {
    send_spi(i,0x00);//Symbol blank
  } while (--i);
}
void MATR_7219_init() {
    __delay_ms(100);
    cs=1; 
    send_spi(0x09, 0x00);  
    send_spi(0x0b, 0x07); 
    send_spi(0x0A, 0x02); 
    send_spi(0x0c, 0x01); 
    clrf();
}

