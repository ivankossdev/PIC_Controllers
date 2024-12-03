#ifndef SETTINGS_H
#define	SETTINGS_H
#include <xc.h>
#include "portsinit.h"
#pragma config FOSC = HS        
#pragma config WDTE = OFF       
#pragma config PWRTE = OFF      
#pragma config CP = OFF         
#pragma config BOREN = OFF      
#pragma config LVP = OFF        
#pragma config CPD = OFF        
#pragma config WRT = OFF 
#define _XTAL_FREQ 16000000
#endif	/* SETTINGS_H */