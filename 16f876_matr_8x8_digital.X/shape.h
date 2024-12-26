#ifndef SHAPE_H
#define	SHAPE_H
#include "spi.h"
#include "matrix.h"
#include "font.h"

char * GetDgigtal(int dig);
void MatrixSpiSendWord(int segment, char data);
void ShowSimvolString(int matrSegmentsCount, int sA[]);

#endif	/* SHAPE_H */
