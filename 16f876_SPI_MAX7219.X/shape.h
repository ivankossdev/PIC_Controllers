#ifndef SHAPE_H
#define	SHAPE_H
#include "spi.h"
#include "matrix.h"

typedef struct {
    int x;
    int y;
} TCoord;

void SetPosition(TCoord * position, int x, int y);
void ShowShape(TCoord * coord);

#endif	/* SHAPE_H */

