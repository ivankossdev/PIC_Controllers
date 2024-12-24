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

void MatrixSendTest(int segment, char data, int c,  char data2) {
    cs = 0;
    SpiSendByte((char)segment);
    SpiSendByte(data);
    int i = c;
    do{
        SpiSendByte((char)segment);
        SpiSendByte( data2);
    }while(--c);
    cs = 1;
}

void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
//    TCoord shapePosition; 
    char * pSimvol = (char *)calloc(8, sizeof(char));
    char * pSimvol2 = (char *)calloc(8, sizeof(char));
//    char Display[8] = {'\0'};
//    bool bR = true;
    
    while(1){
//        SetPosition(&shapePosition, 0, 0); 

        for(int c = 0, d = 9 ; c < 10; c++, d--){
            pSimvol = GetDgigtal(c);
            pSimvol2 = GetDgigtal(d);
            for(int i = 0; i < 8; i++){
                MatrixSendTest(i + 1,pSimvol[i], 1, pSimvol2[i]);
            }
            __delay_ms(500);
        }

        
        __delay_ms(1000);
        MatrixClear();
        MatrixClear();
        __delay_ms(1000);
        
//        for(int i = 0; i < 10; i++){
//            
//            if(bR){
//                pSimvol = GetDgigtal(i);
//                ShowShape(&shapePosition, 8, pSimvol);
//                __delay_ms(250); 
//            }
//            else{
//                pSimvol = GetDgigtal(i);
//                Rotate(pSimvol, Display, 8);
//                ShowShape(&shapePosition, 8, Display);
//                __delay_ms(250); 
//            }
//        }
//        if(bR) bR = false;
//        else bR = true;
    }    
    return;
}

