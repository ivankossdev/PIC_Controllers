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
    char figure[3] = { 0x07, 0x05, 0x07 };
    const unsigned long delay = 250;
    
    while(1){
        
        for(int i = 0; i < 5; i++){
            SetPosition(&shapePosition, i, i);
            
            MovieShape(notMoive, &shapePosition, figure);
            __delay_ms(delay);    

            MovieShape(down, &shapePosition, figure);
            __delay_ms(delay);

            MovieShape(right, &shapePosition, figure);
            __delay_ms(delay);

            MovieShape(up, &shapePosition, figure);
            __delay_ms(delay);

            MovieShape(left, &shapePosition, figure);
            __delay_ms(delay);
        }

    }
    
    return;
}