#include <xc.h>
#include "portsinit.h"

/* ������������� ����� B �� ����� */
void PortBInit(void){
    TRISB = 0x00;   // ���� � �� ����� RB0-RB7
    PORTB = 0x00; 
}
