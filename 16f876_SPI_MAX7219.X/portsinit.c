#include <xc.h>
#include "portsinit.h"


/* Инициализация порта A */
//void PortAInit(void){
//    PORTA = 0x00; 
//    TRISA = 0x00;   // Порт А на выход 
//    ADCON1 |= 0x06; // Перевод с D режим RA0-RA5
//}

/* Инициализация порта B на выход */
void PortBInit(void){
    TRISB = 0x00;   // Порт В на выход RB0-RB7
    PORTB = 0x00; 
}
