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

void TestShiftDispImage(bool *on){
        int i = 32;
        do{
            ShowDisplay();
            __delay_ms(100);
            if(*on){
                ShiftLeftOneBit();
            }else{
                ShifRightOneBit();
                
            }
            
        }while(i--);
        if(*on) *on = false;
        else *on = true;
        __delay_ms(1000);
}

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
    TCrd cord;
    
    while(1){ 
        InsertShapeInSegment((char *)fig_1, SEGMENT_1, 8);
        InsertShapeInSegment((char *)fig_1, SEGMENT_4, 8);
        InsertSimvInSegment(9, SEGMENT_2, 8);
        InsertSimvInSegment(9, SEGMENT_3, 8);
        ShowDisplay();
        __delay_ms(1000);

        for(int i = 0; i <= 10; i++){
            ClearDspArrSgm(SEGMENT_2);
            ClearDspArrSgm(SEGMENT_3);
            InsertSimvInSegment(i / 10, SEGMENT_2, 8);
            InsertSimvInSegment(i % 10, SEGMENT_3, 8);
            ShowDisplay();
            __delay_ms(DELAY);    
        }
        
        __delay_ms(1000);
        
        TestShiftDispImage(&on);
//        
//        ------------------------------------
        int y = 0;
        do{
            for(int x = 0; x < 32; x++){
                cord.x = x;
                cord.y = y;
                InsertWordByCord(&cord);
                ShowDisplay();
                __delay_ms(10);
                ClearDspArr();
            } 
            y++;
        }while(y < 8);
    }    
    return;
}
