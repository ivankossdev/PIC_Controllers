#include "timer.h"
int ic = 10;

void timerOneInit(void){
    T1CKPS0=1;  //Prescaler 8 (1000000/31250/8 = 4 Hz)
    T1CKPS1=1;
    TMR1CS=0;   //Internal clock
    TMR1L=0xee; // 65536 - 31250 = 34286 = 0x85EE
    TMR1H=0x85;
    GIE=1;
    PEIE=1;
    TMR1IE=1;
    TMR1ON=1;
    //    T0IE=1;
}
