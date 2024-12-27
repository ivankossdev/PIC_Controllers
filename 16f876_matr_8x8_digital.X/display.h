#ifndef DISPLAY_H
#define	DISPLAY_H
#include "spi.h"
#include "matrix.h"
#include "font.h"

char * GetDgigtal(int dig);
void MatrixEnableLEDLine(int segment, char data);
void ShowSimvolString(int matrSegmentsCount, int sA[]);
void ClearDisplay(int matrSegmentsCount);
void ShowDisplay(int matrSegmentsCount);

#endif	/* DISPLAY_H */
