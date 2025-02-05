#include <xc.h>
#include <stdbool.h>
#include "settings.h"
#include "portsinit.h"
#include "timer.h"


void main(void) {
    
    PortBInit();
    timerOneInit();
    
    while(1){
        if(flagTimerOne) PORTB |= 1 << 0;
        else PORTB &= ~(1 << 0);

    }
    return;
}
