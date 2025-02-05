#include <xc.h>
#include <stdbool.h>
#include "settings.h"
#include "portsinit.h"
#include "timer.h"

void __interrupt() interruptHandler(void)
{
    if(TMR1IE && TMR1IF)
    {
        TMR1L = 0xee;
        TMR1H = 0x85;
        TMR1IF = 0;
        if(flagTimerOne) flagTimerOne = false;
        else flagTimerOne = true;
    }
}

void main(void) {
    
    PortBInit();
    timerOneInit();
    
    while(1){
        if(flagTimerOne) PORTB |= 1 << 0;
        else PORTB &= ~(1 << 0);

    }
    return;
}
