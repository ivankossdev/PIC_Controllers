#include <xc.h>
#include "settings.h"
#include "spi.h"
#include "matrix.h"
#include "shape.h"

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
        for(int xCoord = 0; xCoord <= 6; xCoord++){
            for(int yCoord = 0; yCoord <= 8; yCoord++){
                SpiClearMatrix();
                SetPosition(&shapePosition, xCoord, yCoord);
                ShowShape(&shapePosition);
                __delay_ms(100);
            }         
        }
        SpiClearMatrix();
    }
    
    return;
}