#ifndef SPI_H
#define	SPI_H
#include <xc.h>
#include "settings.h"
#define cs RA5
void SpiInit(void);
void SpiSendByte(char data);
#endif	/* SPI_H */

