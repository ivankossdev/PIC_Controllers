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
    TCoord shapePosition; 
    char * pSimvol = calloc(8, sizeof(char));
    char Display[8] = {'\0'};
    bool bR = true;
    
    while(1){
        SetPosition(&shapePosition, 0, 0); 
        for(int i = 0; i < 10; i++){
            
            if(bR){
                pSimvol = GetDgigtal(i);
                ShowShape(&shapePosition, 8, pSimvol);
                __delay_ms(250); 
            }
            else{
                pSimvol = GetDgigtal(i);
                Rotate(pSimvol, Display, 8);
                ShowShape(&shapePosition, 8, Display);
                __delay_ms(250); 
            }
        }
        if(bR) bR = false;
        else bR = true;
    }    
    
    return;
}
