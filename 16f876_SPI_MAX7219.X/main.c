#include <xc.h>
#include "settings.h"
#include "spi.h"
#include "matrix.h"

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
    MatrixInit();
    PortBInit();
    
    int sh = 0;
    int bar = 0;
    
    while(1){
        for(int i = 1; i <= 8; i++){
            SpiClearMatrix();
            bar = 1 << sh;
            SendToSegment((char)i, (char)bar);
            __delay_ms(500);
        }
        sh++;
        if(sh > 7){
            bar = 0;
            sh = 0;      
            SpiClearMatrix();
        }
    }
    
    return;
}