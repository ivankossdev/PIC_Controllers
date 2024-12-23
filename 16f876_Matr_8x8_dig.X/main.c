#include <xc.h>
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
    TCoord shapePosition; 

    while(1){
        SetPosition(&shapePosition, 0, 1); 
        ShowDigital(&shapePosition, 8, (char*)simvol_4);
        __delay_ms(1000);
        MatrixClear();
        __delay_ms(1000);
    }    
    return;
}
