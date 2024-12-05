#include "spi.h"

/****pic 16f876****
 * pin  7 RA5 CS  *
 * pin 14 RC3 CLK *
 * pin 16 RC5 SDO *
 *******************/

void SpiInit() {
    TRISC |= 0x10;  // MISO in
    TRISC &= ~0x28; // MOSI sck out
    TRISA &= ~0x20; // RA5 CS 
    PORTA &= ~0x20; 
    SSPCON = 0x30;  // SSPEN=1 SKP=1 SSPM0=0 SSPM1=0 SSPM2=0 SSPM3=0
    SSPSTAT = 0x80; // SMP=1;
}

void SpiSendByte(char data) {
    SSPBUF = data;
    while (!SSPIF);
    SSPIF = 0;
}

void SpiSendBus(char rg, char dt) {
    cs = 0;
    SpiSendByte(rg);
    SpiSendByte(dt);
    cs = 1;
}

