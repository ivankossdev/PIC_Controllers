#include <xc.h>
#include <stdbool.h>
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
    int countElemntArray = 3;
    const unsigned long delay = 100;
    
    while(1){
        int step = 0;
        SetPosition(&shapePosition, 0, 0);
        MovieShape(notMoive, &shapePosition, figure, countElemntArray); 
        
        do{
            for(int i = 0; i < 5; i++){
                switch (step){
                    case 0: 
                        MovieShape(right, &shapePosition, figure, countElemntArray); 
                        break;
                    case 1: 
                        MovieShape(down, &shapePosition, figure, countElemntArray); 
                        break;
                    case 2: 
                        MovieShape(left, &shapePosition, figure, countElemntArray); 
                        break;
                    case 3: 
                        MovieShape(up, &shapePosition, figure, countElemntArray); 
                        break;
                }
                __delay_ms(delay); 
            }
            step++;  
        } while(step < 4);
    }
    
    return;
}