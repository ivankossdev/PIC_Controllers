#ifndef MATRIX_H
#define	MATRIX_H

#include <xc.h>
#include "settings.h"
#include "spi.h"

void MatrixInit(void);
void SpiClearMatrix (void);
void SendToSegment(char rg, char dt );
#endif	/* MATRIX_H */

