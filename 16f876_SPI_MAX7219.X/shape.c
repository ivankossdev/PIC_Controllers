#include "shape.h"

void SetPosition(TCoord * position, int x, int y){
    position->x = x;
    position->y = y;
}

void ShowShape(TCoord * coord){
    for(int pos = 1 + coord->x; pos <= 2 + coord->x; pos++){
       SendToSegment(pos, (char)(0x03 << coord->y));
    }
}

