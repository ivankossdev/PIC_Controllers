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
void MatrixSpiSendWord(int segment, char data){
    SpiSendByte((char)segment);
    SpiSendByte(data);
}

void ShowSimvolString(int matrSegmentsCount, int sA[]){
    for(int i = 0; i < 8; i++){
        cs = 0;
        for(int _i = matrSegmentsCount; _i >= 0; _i--){
            MatrixSpiSendWord(i + 1, GetDgigtal(sA[_i])[i]);
        }
        cs = 1;
    }
}

void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    int sA[4] = {4, 6, 1, 9};
    int MatrSegments = 4; 
    
    while(1){ 
        ShowSimvolString(MatrSegments, sA);
        __delay_ms(1000);
        MatrixClear();
        MatrixClear();
        __delay_ms(2000);
        
    }    
    return;
}














//        for(int digital = 0; digital <= 99; digital++){
//            int s0 = (digital / 10) % 10;
//            int s1 = digital % 10;
//            MatrixPrint(s1, s0);
//            __delay_ms(250);
//        }