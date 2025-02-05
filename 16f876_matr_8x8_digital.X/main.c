#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "settings.h"
#include "spi.h"
#include "timer1.h"
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

void __interrupt() tim1ISR(void)
{
    if(TMR1IE&&TMR1IF)
    {
        TMR1L=0xEE;
        TMR1H=0x85;
        TMR1IF=0;
    }
}


void main(void) {
    SpiInit();
    MatrixInit();
    PortBInit();
    ClearDisplay();
    timerOneInit();
    
    while(1){ 
        RunLeftString("Hello led project 9-127.ru");
        int i = 16;
        while(i){
            ShowDisplay();
            __delay_ms(100);
            ShiftLeftOneBit();
            i--;
        }
    }    
    return;
}
