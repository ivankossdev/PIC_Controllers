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

void MatrixSendTest(int segment, char data, int c,  char data2) {
    cs = 0;
    MatrixSpiSendWord((char)segment, data);
    int i = c;
    do{
        MatrixSpiSendWord((char)segment, data2);
    }while(--c);
    cs = 1;
}

void MatrixPrint(int seg_1, int seg_0){
    for(int i = 0; i < 8; i++){
        MatrixSendTest(i + 1,GetDgigtal(seg_1)[i], 1, GetDgigtal(seg_0)[i]);
    }
}

void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    
    while(1){ 
        
        for(int digital = 0; digital <= 99; digital++){
            int s0 = (digital / 10) % 10;
            int s1 = digital % 10;
            MatrixPrint(s1, s0);
            __delay_ms(100);
        }


        __delay_ms(1000);
        MatrixClear();
        MatrixClear();
        __delay_ms(1000);
        
    }    
    return;
}

