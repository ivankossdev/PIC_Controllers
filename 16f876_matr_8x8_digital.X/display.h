#ifndef DISPLAY_H
#define	DISPLAY_H
#include "spi.h"
#include "matrix.h"
#include "font.h"
#include <stdbool.h>
#define MTR_DSP 4
#define SEGMENT_1 0
#define SEGMENT_2 1
#define SEGMENT_3 2
#define SEGMENT_4 3

typedef struct{
    int x;
    int y;
} TCrd;

void MatrixEnableLEDLine(int segment, char data);
void ShowSimvolString(int matrSegmentsCount, int sA[]);
void ClearDisplay(void);
void ShowDisplay(void);
void InsertShapeInSegment(char *ar, int matrSegmant, int arElements);
void ClearDspArr(void);
void ClearDspArrSgm(int seg);
void ShifRightOneBit(void);
void ShiftLeftOneBit(void);
void InsertWordByCord(TCrd *cord, char word);
void InsertShapeByCord(TCrd *cord, char shape[], int cntArray);
void InsertSimvByCord(TCrd *cord, int dig);

#endif	/* DISPLAY_H */
