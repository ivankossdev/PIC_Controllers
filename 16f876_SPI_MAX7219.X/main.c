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
        for(int k = 0; k <= 6; k++){
            for(int sh = 0; sh <= 8; sh++){
                SpiClearMatrix();
                for(int y_coord = 1 + k; y_coord <=2 + k; y_coord++){
                   SendToSegment(y_coord, (char)(0x03 << sh));
                }
                __delay_ms(100);
            }         
        }
        SpiClearMatrix();
    }
    
    return;
}