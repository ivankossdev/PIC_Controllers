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
void RotateDirection(int step, char * array_, int _countElemntArray );
void ChangeOfCoordinates(TCoord * _shapePosition, char * _figure, int _countElemntArray);


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
    }    
    return;
}


void ChangeOfCoordinates(TCoord * _shapePosition, char * _figure, int _countElemntArray){
    const unsigned long delay = 100;
    char * rotateArray = calloc((size_t)_countElemntArray, sizeof(char));
    CopyArray(rotateArray, _figure, _countElemntArray);
    
    int step = 0;
        do{
            for(int i = 0; i < 5; i++){
                switch (step){
                    case 0: 
                        MovieShape(right, _shapePosition, rotateArray, _countElemntArray); 
                        break;
                    case 1: 
                        MovieShape(down, _shapePosition, rotateArray, _countElemntArray); 
                        break;
                    case 2: 
                        MovieShape(left, _shapePosition, rotateArray, _countElemntArray); 
                        break;
                    case 3: 
                        MovieShape(up, _shapePosition, rotateArray, _countElemntArray); 
                        break;
                }
                __delay_ms(delay); 
                
            } 
            RotateDirection(step, rotateArray, _countElemntArray);
            step++;  
        } while(step < 4);
        
        free(rotateArray);
}

void RotateDirection(int step, char * array_, int _countElemntArray ){
    switch (step){
        case 0:
            Reverse(array_, _countElemntArray);
            Rotate(array_, _countElemntArray);
            break;
        case 1:
            Rotate(array_, _countElemntArray);
            Reverse(array_, _countElemntArray);
            break;
        case 2:
            for(int i = 0; i < 3; i++){
                Rotate(array_, _countElemntArray);
            }
            break;
    }
}