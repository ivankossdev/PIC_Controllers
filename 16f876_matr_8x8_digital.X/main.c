#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "settings.h"
#include "spi.h"
#include "matrix.h"
#include "shape.h"
#include "font.h"

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
    int sA[4] = {'\0'};
    int MatrSegments = 4; 
    
    while(1){ 
        for(int digitalUP = 0, digitalDOWN = 99; digitalUP <= 99; digitalUP++, digitalDOWN--){
            sA[3] = digitalUP % 10;
            sA[2] = (digitalUP / 10) % 10;
            sA[1] = digitalDOWN % 10;
            sA[0] = (digitalDOWN / 10) % 10;
            ShowSimvolString(MatrSegments, sA);
            __delay_ms(250);
        }
        
        __delay_ms(1000);
        MatrixClear();
        MatrixClear();
        __delay_ms(1000);
        
    }    
    return;
}
