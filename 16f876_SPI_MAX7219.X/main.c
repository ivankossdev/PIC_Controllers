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

void ChangeOfCoordinates(TCoord * _shapePosition, char * _figure, int _countElemntArray){
    const unsigned long delay = 100;
    int step = 0;
        do{
            for(int i = 0; i < 5; i++){
                switch (step){
                    case 0: 
                        MovieShape(right, _shapePosition, _figure, _countElemntArray); 
                        break;
                    case 1: 
                        MovieShape(down, _shapePosition, _figure, _countElemntArray); 
                        break;
                    case 2: 
                        MovieShape(left, _shapePosition, _figure, _countElemntArray); 
                        break;
                    case 3: 
                        MovieShape(up, _shapePosition, _figure, _countElemntArray); 
                        break;
                }
                __delay_ms(delay); 
            } 
            step++;  
        } while(step < 4);
    
}

void invert(char * array, int countElemnt)
{
    for(int i = 0, j = countElemnt - 1; i < j; i++, j--)
    {
        char t = array[i];
        array[i] = array[j];
        array[j] = t;
    }  
}

/*
 * 0b0000_0110 -> 0x06
 * 0b0000_0101 -> 0x05
 * 0b0000_0110 -> 0x06
 * 
 * 0b0000_0111 -> 0x07
 * 0b0000_0101 -> 0x05
 * 0b0000_0010 -> 0x02
 */

void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    
    TCoord shapePosition; 
    char square_1[3] = { 0x07, 0x05, 0x02 };
    int countElemntArray = 3;
    while(1){
        SetPosition(&shapePosition, 0, 0); 
        ChangeOfCoordinates(&shapePosition, square_1, countElemntArray);
        invert(square_1, countElemntArray);
    }    
    return;
}