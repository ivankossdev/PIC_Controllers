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

void MovieShape(enum MovieDirection dir, TCoord * _shapePosition, char * shapeArray, int countElemntArray){
    
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
    ShowShape(_shapePosition, countElemntArray, shapeArray);
}

void Rotate(char * array_, int countElemntArray){

    char * res = calloc((size_t)countElemntArray, sizeof(char));

    if (res){
        for(int _i = countElemntArray - 1; _i >= 0; _i--){
            for(int i = countElemntArray - 1, x = 0; i >= 0; i--, x++){
                res[_i] |= ((array_[x] >> _i ) & 1) << i;
            }
        }
        InsertResult(array_, res, countElemntArray);
    }
    free(res);
}

void Reverse(char * array_, int countElemntArray)
{
    for(int i = 0, j = countElemntArray - 1; i < j; i++, j--)
    {
        char t = array_[i];
        array_[i] = array_[j];
        array_[j] = t;
    }  
}

void InsertResult(char * array_, char * res, int countElemntArray){
    for(int y = 0; y < countElemntArray; y++){
        array_[y] = res[y];
    }
}
