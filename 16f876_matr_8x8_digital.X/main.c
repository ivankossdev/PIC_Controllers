#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "settings.h"
#include "spi.h"
#include "matrix.h"
#include "display.h"
#include "font.h"
#define DELAY 250

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

        
        InsertShapeInDspArr((char *)fig_0, 7, 2, 5);
        ShowDisplay();
        __delay_ms(DELAY);
        
        InsertShapeInDspArr((char *)fig_0, 4, 1, 5);
        ShowDisplay();
        __delay_ms(DELAY);
        
        InsertShapeInDspArr((char *)fig_0, 6, 0, 5);
        ShowDisplay();
        __delay_ms(DELAY);
        
        for(int i = 0; i <= 9; i++){
            ClearDspArrSgm(3);
            InsertSimvInDspArr(i, 7, 3, 8);
            ShowDisplay();
            __delay_ms(DELAY);    
        }
        
        __delay_ms(1000);
        
        ClearDspArr();
        ClearDisplay();
        __delay_ms(DELAY);
        
    }    
    return;
}
