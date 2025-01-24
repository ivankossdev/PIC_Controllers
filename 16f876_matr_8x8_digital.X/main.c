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

const char fig_2[8] = {
    0b00001000, 
    0b00001100, 
    0b01111110, 
    0b01111111, 
    0b01111110, 
    0b00001100, 
    0b00001000, 
    0b00000000
};

void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    ClearDisplay();
    bool on = true;
    TCrd cord;
    
    while(1){ 
        int stp = 32; 
        
        for(int i = 0; i < 8; i++){
            SliceShapeByCordY((char *)fig_1, i);
            ShowDisplay();
            __delay_ms(100);
            ShiftLeftOneBit();
            stp--;
        }
        
        for(int i = 0; i < 8; i++){
            SliceShapeByCordY((char *)fig_2, i);
            ShowDisplay();
            __delay_ms(100);
            ShiftLeftOneBit();
            stp--;
        } 
        while(stp){
            ShowDisplay();
            __delay_ms(100);
            ShiftLeftOneBit();
            stp--;
        }
        
        __delay_ms(1000);
        ClearDspArr();
        
        InsertShapeInSegment((char *)fig_1, SEGMENT_1, 8);
        InsertShapeInSegment((char *)fig_1, SEGMENT_4, 8);
        cord.x = 10;
        cord.y = 0;
        InsertSimvByCord(&cord, 9);
        cord.x = 17;
        cord.y = 0;
        InsertSimvByCord(&cord, 9);
        ShowDisplay();
        __delay_ms(1000);

        for(int i = 0; i <= 20; i++){
            ClearDspArrSgm(SEGMENT_2);
            ClearDspArrSgm(SEGMENT_3);
            
            
            cord.y = 0;
            if((i / 10) == 1){
                cord.x = 12;
            }
            else{
                cord.x = 10; 
            }
            InsertSimvByCord(&cord, i / 10);
            
            cord.y = 0;
            if((i % 10) == 1){
                cord.x = 19;
            }else{
                cord.x = 17;
            }
            InsertSimvByCord(&cord, i % 10);
            ShowDisplay();
            __delay_ms(DELAY);    
        }
        
        __delay_ms(1000);
        
        TestShiftDispImage(&on);

//        ------------------------------------

        for(int x = 0; x < 33; x++){
            cord.x = x;
            cord.y = 0;
            if(x > 10) cord.y = 1;
            InsertShapeByCord(&cord, (char *)fig_2, 8);
            ShowDisplay();
            __delay_ms(50);
            ClearDspArr();
        } 
        
        __delay_ms(1000);
    }    
    return;
}

