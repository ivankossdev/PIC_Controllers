#include <xc.h>
#include "portsinit.h"


/* ������������� ����� A */
//void PortAInit(void){
//    PORTA = 0x00; 
//    TRISA = 0x00;   // ���� � �� ����� 
//    ADCON1 |= 0x06; // ������� � D ����� RA0-RA5
//}

/* ������������� ����� B �� ����� */
void PortBInit(void){
    TRISB = 0x00;   // ���� � �� ����� RB0-RB7
    PORTB = 0x00; 
}
