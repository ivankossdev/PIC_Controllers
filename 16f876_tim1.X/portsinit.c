#include <xc.h>
#include "portsinit.h"

/* Инициализация порта B на выход */
void PortBInit(void){
    TRISB = 0x00;   // Порт В на выход RB0-RB7
    PORTB = 0x00; 
}
