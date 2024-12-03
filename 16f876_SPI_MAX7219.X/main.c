#include <xc.h>
#include "settings.h"
#include "spi.h"

/****************PIC16F876***************
 * Connection PICkit4                   *
 * pin 28 RB7/PGD  -> green             *
 * pin 27 RB6/PGC  -> white             *
 * pin  1 MCLR/VPP -> orange            *
 * *****************SPI******************
 * pin  7 RA5      -> CS                *
 * pin 14 RC3      -> CLK               *
 * pin 16 RC5      -> DIN               *
 *******************END******************/

void main(void) {
//    spi_init();
//    MATR_7219_init();
    PortBInit();
    
    while(1){
        PORTB = 0b00011111;
        __delay_ms(1000);
        PORTB = 0x00;
        __delay_ms(1000);
    }
    
    return;
}