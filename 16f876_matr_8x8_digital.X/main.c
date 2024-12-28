#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "settings.h"
#include "spi.h"
#include "matrix.h"
#include "display.h"
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

void Demo(void){
    int sA[4] = {'\0'};
    int counter = 10;
    for(int digitalUP = 0, digitalDOWN = counter; digitalUP <= counter; digitalUP++, digitalDOWN--){
        sA[3] = digitalUP % 10;
        sA[2] = (digitalUP / 10) % 10;
        sA[1] = digitalDOWN % 10;
        sA[0] = (digitalDOWN / 10) % 10;
        ShowSimvolString(MTR_DSP, sA);
        __delay_ms(100);
    }
    __delay_ms(1000);
    ClearDisplay();
    __delay_ms(1000);
}

void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    Demo();
    while(1){ 
        
        InsertInDisplayArray((char *)fig_0, 7, 2, 5);
        ShowDisplay();
        __delay_ms(1000);
        
        InsertInDisplayArray((char *)fig_0, 4, 1, 5);
        ShowDisplay();
        __delay_ms(1000);
        ClearDisplayArray();
        ClearDisplay();
        __delay_ms(1000);
        
    }    
    return;
}
