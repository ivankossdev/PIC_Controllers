#include "shape.h"

void SetPosition(TCoord * position, int x, int y){
    position->x = x;
    position->y = y;
} 

void ShowShape(TCoord * coord, int countElemntArray, char * shapeArray){
    int _pos = 0;
    for(int pos = 1 + coord->x; pos <= countElemntArray + coord->x; pos++){
       _pos = pos - 1 - coord->x;
       SendToSegment(pos, (char)(shapeArray[_pos] << coord->y));
    }
}

int WidthLimit(int lenghtMatrix, int lengthShape){
    return lenghtMatrix - lengthShape;
}

void Movie(TCoord * _shapePosition, int _widthLimit, char * _figure){
    for(int xCoord = 0; xCoord <= _widthLimit; xCoord++){
        for(int yCoord = 0; yCoord <= _widthLimit + WIDTH_SHAPE; yCoord++){
            SpiClearMatrix();
            SetPosition(_shapePosition, xCoord, yCoord);
            ShowShape(_shapePosition, 3, _figure);
            __delay_ms(250);
        }         
    }
    SpiClearMatrix();
}
