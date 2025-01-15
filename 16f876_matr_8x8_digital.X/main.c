#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "settings.h"
#include "spi.h"
#include "matrix.h"
#include "display.h"
#include "font.h"
#define DELAY 50


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

const char fig_1[8] = { 
    0b11000011, 
    0b11000011, 
    0b00100100, 
    0b00011000, 
    0b00011000, 
    0b00100100, 
    0b11000011, 
    0b11000011 };

void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    ClearDisplay();
    bool on = true;
    
    while(1){ 
        InsertShapeInDspArr((char *)fig_1, 7, SEGMENT_1, 8);
        InsertShapeInDspArr((char *)fig_1, 7, SEGMENT_4, 8);
        InsertSimvInDspArr(9, 7, SEGMENT_2, 8);
        InsertSimvInDspArr(9, 7, SEGMENT_3, 8);
        ShowDisplay();
        __delay_ms(1000);

        for(int i = 0; i <= 10; i++){
            ClearDspArrSgm(SEGMENT_2);
            ClearDspArrSgm(SEGMENT_3);
            InsertSimvInDspArr(i / 10, 7, SEGMENT_2, 8);
            InsertSimvInDspArr(i % 10, 7, SEGMENT_3, 8);
            ShowDisplay();
            __delay_ms(DELAY);    
        }
        
        __delay_ms(1000);
        
        
        int i = 32;
        do{
            ShowDisplay();
            __delay_ms(100);
            if(on){
                ShiftLeftOneBit();
            }else{
                ShifRightOneBit();
                
            }
            
        }while(i--);
        if(on) on = false;
        else on = true;
        __delay_ms(1000);
    }    
    return;
}
