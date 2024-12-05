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
    
    
    while(1){
        for(int x = 1; x <=4; x++){
            SendToSegment(x, 0x0f);
        }
        __delay_ms(500);
        for(int x = 5; x <=8; x++){
            SendToSegment(x, 0xf0);
        }
        __delay_ms(500);
        SpiClearMatrix();
        
        for(int x = 5; x <=8; x++){
            SendToSegment(x, 0x0f);
        }
        __delay_ms(500);
        for(int x = 1; x <=4; x++){
            SendToSegment(x, 0xf0);
        }
        __delay_ms(500);
        SpiClearMatrix();
//        __delay_ms(500);
    }
    
    return;
}