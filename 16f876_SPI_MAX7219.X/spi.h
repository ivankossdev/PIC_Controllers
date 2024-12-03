#ifndef SPI_H
#define	SPI_H
#include <xc.h>
#include "settings.h"
void spi_init(void);
void send_byte_spi(char data);
void send_spi(char rg, char dt );
void MATR_7219_init(void);
void clrf (void);
#endif	/* SPI_H */

