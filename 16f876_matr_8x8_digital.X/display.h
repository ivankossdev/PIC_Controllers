#ifndef DISPLAY_H
#define	DISPLAY_H
#include "spi.h"
#include "matrix.h"
#include "font.h"
#define MTR_DSP 4

char * GetDgigtal(int dig);
void MatrixEnableLEDLine(int segment, char data);
void ShowSimvolString(int matrSegmentsCount, int sA[]);
void ClearDisplay(void);
void ShowDisplay(void);
void InsertInDisplayArray(char * ar,int cY, int cX, int arElements);
void ClearDisplayArray(void);

#endif	/* DISPLAY_H */
