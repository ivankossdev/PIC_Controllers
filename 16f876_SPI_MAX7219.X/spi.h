#ifndef SPI_H
#define	SPI_H
#include <xc.h>
#include "settings.h"
void SpiInit(void);
void SpiSendByte(char data);
void SpiSendBus(char rg, char dt );
void MATR_7219_init(void);
void SpiClearMatrix (void);
#endif	/* SPI_H */

