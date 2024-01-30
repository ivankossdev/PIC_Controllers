#include <xc.h>
#include "settings.h"

void ConrolInit(void);

void main(void) {
    
    ConrolInit();
    PORTB = 0x00;
    
    while(1){
        PORTB |= 0x01;
        __delay_ms(1000);
        
        PORTB &= ~0x01;
        __delay_ms(1000);
    }
    return;
}

void ConrolInit(void){
    PORTB = 0x00; // Output port
    TRISB = 0x00;
}