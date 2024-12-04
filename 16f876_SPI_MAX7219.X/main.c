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
    SpiInit();
    MATR_7219_init();
    PortBInit();
    int sh = 0;
    while(1){
        for(int i = 1; i < 9; i++){
            if(i <= 5){
                PORTB = 0x01 << (i - 1);
            }
            SpiSendBus(i, (1 << sh));
            __delay_ms(100);
        }
        sh++;
        if(sh > 7){
            sh = 0;      
            SpiClearMatrix();
        }
        PORTB = 0x00;
        __delay_ms(100);
    }
    
    return;
}