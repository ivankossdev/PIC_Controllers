#include "timer.h"

void timerOneInit(void){
    T1CKPS0=1;  //Prescaler 8 (1000000/31250/8 = 4 Hz)
    T1CKPS1=1;
    TMR1CS=0;   //Internal clock
    TMR1L=0xEE; // 65536 - 31250 = 34286 = 0x85EE
    TMR1H=0x85;
    T0IE=1;
    GIE=1;
    PEIE=1;
    TMR1IE=1;
    TMR1ON=1;
}

void __interrupt() tim1ISR(void)
{
    if(TMR1IE&&TMR1IF)
    {
        TMR1L=0xEE;
        TMR1H=0x85;
        TMR1IF=0;
        if(flagTimerOne) flagTimerOne = false;
        else flagTimerOne = true;
    }
}