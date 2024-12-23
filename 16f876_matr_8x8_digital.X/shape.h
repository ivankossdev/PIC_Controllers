#ifndef SHAPE_H
#define	SHAPE_H
#include "spi.h"
#include "matrix.h"
#include "font.h"

#define WIDTH_MATR 8
#define WIDTH_SHAPE 3

typedef struct {
    int x;
    int y;
} TCoord;

void SetPosition(TCoord * position, int x, int y);
void ShowShape(TCoord * coord, int countElemntArray, char * shapeArray);
char * GetDgigtal(int dig);

#endif	/* SHAPE_H */
