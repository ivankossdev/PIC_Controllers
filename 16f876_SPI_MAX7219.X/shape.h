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

enum MovieDirection{
    down,
    up,
    left,
    right,
    notMoive
};

void SetPosition(TCoord * position, int x, int y);
void ShowShape(TCoord * coord, int countElemntArray, char * shapeArray);
void MovieDown(TCoord * _shapePosition);
void MovieUp(TCoord * _shapePosition);
void MovieLeft(TCoord * _shapePosition);
void MovieRigth(TCoord * _shapePosition);                                      
void MovieShape(enum MovieDirection dir, TCoord * _shapePosition, char * shapeArray, int countElemntArray);
void Rotate(char * array_, int length);
void Reverse(char * array, int countElemnt);
void InsertResult(char * array_, char * res, int countElemntArray);

#endif	/* SHAPE_H */
