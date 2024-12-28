#ifndef DISPLAY_H
#define	DISPLAY_H
#include "spi.h"
#include "matrix.h"
#include "font.h"
#define MTR_DSP 4

void MatrixEnableLEDLine(int segment, char data);
void ShowSimvolString(int matrSegmentsCount, int sA[]);
void ClearDisplay(void);
void ShowDisplay(void);
void InsertShapeInDspArr(char * ar,int cY, int cX, int arElements);
void ClearDisplayArray(void);
void InsertSimvInDspArr(int dig, int cY, int cX, int arElements);

#endif	/* DISPLAY_H */
