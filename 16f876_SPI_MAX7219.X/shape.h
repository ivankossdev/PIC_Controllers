#ifndef SHAPE_H
#define	SHAPE_H
#include "spi.h"
#include "matrix.h"

#define WIDTH_MATR 8
#define WIDTH_SHAPE 3

typedef struct {
    int x;
    int y;
} TCoord;

void SetPosition(TCoord * position, int x, int y);
void ShowShape(TCoord * coord, int countElemntArray, char * shapeArray);
int WidthLimit(int lenghtMatrix, int lengthShape);
void Movie(TCoord * _shapePosition, int _widthLimit, char * _figure);
#endif	/* SHAPE_H */
