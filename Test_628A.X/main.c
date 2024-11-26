#include <xc.h>
#include "ConfBits.h"

/****************PIC16F628A**************
 * Connection PICkit4                   *
 * pin 13 RB7/PGD  -> green             *
 * pin 12 RB6/PGC  -> white             *
 * pin  4 MCLR/VPP -> orange            *
 *******************END******************/

void PortOn();

void main(void) {
    TRISB = 0x00; // порт В на выход
    PORTB = 0x00;
    TRISA = 0x00; // порта А на выход
    PORTA = 0x00;
    CMCON = 0x07; // Компаратор выключен 
    while(1){
        PortOn();
    }
    
    return;
}

void PortOn(){
    
    for(int i = 0; i < 8; i++ ){
        PORTB = 0x03 << i;
    }
    
    PORTB = 0x00;
    PORTB = 0xff;
    PORTB = 0x00;
}
