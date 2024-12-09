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

void MovieDown(TCoord * _shapePosition){
    _shapePosition->y++;
}

void MovieUp(TCoord * _shapePosition){
    _shapePosition->y--;
}

void MovieLeft(TCoord * _shapePosition){
    _shapePosition->x--;
}

void MovieRigth(TCoord * _shapePosition){
    _shapePosition->x++;
}

void MovieShape(enum MovieDirection dir, TCoord * _shapePosition, char * shapeArray){
    
    switch (dir){
        case down: 
            MovieDown(_shapePosition);
            break;
        case up: 
            MovieUp(_shapePosition);
            break;
        case left: 
            MovieLeft(_shapePosition);
            break;
        case right:
            MovieRigth(_shapePosition);
            break;
        case notMoive:
            break;
    }   
    
    SpiClearMatrix();
    ShowShape(_shapePosition, 3, shapeArray);
}
