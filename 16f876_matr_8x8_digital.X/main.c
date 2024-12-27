#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "settings.h"
#include "spi.h"
#include "matrix.h"
#include "shape.h"
#include "font.h"
#define MTR_DSP 4

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


void ShowDisplay(int matrSegmentsCount){
    for(int ledLineMatr = 0; ledLineMatr < 8; ledLineMatr++){
        cs = 0;
        for(int segMatr = matrSegmentsCount; segMatr >= 0; segMatr--){
            /* Цикл передает в матрицу значение массива 
             * display[сегмент матрицы][0 - 8 линейка светодиода] 
             */
            MatrixSpiSendWord(ledLineMatr + 1, display[segMatr][ledLineMatr]);
        }
        cs = 1;
    }
}


void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    int sA[4] = {'\0'};
    
    while(1){ 
        int counter = 10;
        for(int digitalUP = 0, digitalDOWN = counter; digitalUP <= counter; digitalUP++, digitalDOWN--){
            sA[3] = digitalUP % 10;
            sA[2] = (digitalUP / 10) % 10;
            sA[1] = digitalDOWN % 10;
            sA[0] = (digitalDOWN / 10) % 10;
            ShowSimvolString(MTR_DSP, sA);
            __delay_ms(250);
        }
        
        MatrixClear();
        MatrixClear();
        __delay_ms(1000);
        
        ShowDisplay(MTR_DSP);
        __delay_ms(1000);
        
        MatrixClear();
        MatrixClear();
        __delay_ms(1000);
        
    }    
    return;
}
