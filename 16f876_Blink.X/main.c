#include <xc.h>
#include "settings.h"

void PortslInit(void);
void Blink();

void main(void) {
    
    PortslInit();
    PORTB = 0x00;
    
    while(1){
        Blink();
    }
    return;
}

void Blink(){
    for(int i = 0; i < 3; i++){
        PORTB = 0x01 << i;
        __delay_ms(250);
    }
    PORTB = 0x00;
    __delay_ms(250);
}

void PortslInit(void){
    PORTB = 0x00; // Output port
    TRISB = 0x00;
}