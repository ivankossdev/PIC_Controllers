#include "matrix.h"

/******pic 16f876******
 * pin  7 RA5 -> CS   *
 * pin 14 RC3 -> CLK  *
 * pin 16 RC5 -> DIN  *
 **********************/

void SpiClearMatrix (void)
{
  char i = 8;
  do
  {
    SpiSendBus(i, 0x00); 
  } while (--i);
}

void MATR_7219_init(void) {
    __delay_ms(100);
    cs=1; 
    SpiSendBus(0x09, 0x00);  
    SpiSendBus(0x0b, 0x07); 
    SpiSendBus(0x0A, 0x02); 
    SpiSendBus(0x0c, 0x01); 
    SpiClearMatrix();
}
