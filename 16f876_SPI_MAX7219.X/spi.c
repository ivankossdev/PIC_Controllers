#include "spi.h"
#define cs RA5

/**************
 * pic 16f876 *
 * RA5-> CS   *
 * RC3-> CLK  *
 * RC5-> DIN  *
 **************/
void SpiInit() {
    
    TRISC |= 0x10;  // miso in
    TRISC &= ~0x28; // mosi sck out
    TRISA &= ~0x20; // RA5 CS 
    PORTA &= ~0x20; 
    SSPCON = 0x30;  // SSPEN=1 SKP=1 SSPM0=0 SSPM1=0 SSPM2=0 SSPM3=0
    SSPSTAT = 0x80; // SMP=1;
}

void SpiSendByte(char data) {
    SSPBUF = data;
    while (!SSPIF);
    SSPIF = 0;
}

void SpiSendBus(char rg, char dt) {
    cs = 0;
    SpiSendByte(rg);
    SpiSendByte(dt);
    cs = 1;
}
void SpiClearMatrix (void)
{
  char i=8;
  do
  {
    SpiSendBus(i,0x00);//Symbol blank
  } while (--i);
}
void MATR_7219_init() {
    __delay_ms(100);
    cs=1; 
    SpiSendBus(0x09, 0x00);  
    SpiSendBus(0x0b, 0x07); 
    SpiSendBus(0x0A, 0x02); 
    SpiSendBus(0x0c, 0x01); 
    SpiClearMatrix();
}

