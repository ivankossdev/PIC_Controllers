#include <xc.h>
#include "portsinit.h"


/* Инициализация порта B на выход */
void PortBInit(void){
    TRISB = 0x00;
    PORTB = 0x00; 
}

void PortAInit(void){
    TRISA = 0x00;
    PORTA = 0x00;
}

void PortCInit(void){
    TRISC = 0x00;
    PORTB = 0x00;
}