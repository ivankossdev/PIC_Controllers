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
void MovieDown(TCoord * _shapePosition);
void MovieUp(TCoord * _shapePosition);
void MovieLeft(TCoord * _shapePosition);
void MovieRigth(TCoord * _shapePosition);

#endif	/* SHAPE_H */
