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

void Clear(char * _array, int length){
    for(int i = 0; i < length; i++){
        _array[i] = 0;
    }
}

void Rotate(char * _array, char * res, int length){
    Clear(res, length);
    for(int _i = length - 1; _i >= 0; _i--){
        for(int i = length - 1, x = 0; i >= 0; i--, x++){
            res[_i] |= ((_array[x] >> _i ) & 1) << i;
        }
    }
}

void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    TCoord shapePosition; 
    char * pSimvol = calloc(8, sizeof(char));
    char Simvol[8] = {'\0'};
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
                Rotate(pSimvol, Simvol, 8);
                ShowShape(&shapePosition, 8, Simvol);
                __delay_ms(250); 
            }
        }
        if(bR) bR = false;
        else bR = true;
        
    }    
    
    return;
}
