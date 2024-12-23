#include "shape.h"

void SetPosition(TCoord * position, int x, int y){
    position->x = x;
    position->y = y;
} 

void ShowShape(TCoord * coord, int countElemntArray, char * shapeArray){
    int _pos = 0;
    for(int pos = 1 + coord->x; pos <= countElemntArray + coord->x; pos++){
       _pos = pos - 1 - coord->x;
       MatrixSendToSegment(pos, (char)(shapeArray[_pos] << coord->y));
    }
}

char * GetDgigtal(int dig){
    char * pDigial = calloc(8, sizeof(char));
    switch(dig){
        case 0: pDigial = (char *)simvol_0; break;
        case 1: pDigial = (char *)simvol_1; break;
        case 2: pDigial = (char *)simvol_2; break;
        case 3: pDigial = (char *)simvol_3; break;
        case 4: pDigial = (char *)simvol_4; break;
        case 5: pDigial = (char *)simvol_5; break;
        case 6: pDigial = (char *)simvol_6; break;
        case 7: pDigial = (char *)simvol_7; break;
        case 8: pDigial = (char *)simvol_8; break;
        case 9: pDigial = (char *)simvol_9; break;
    }

    return pDigial;
}

void Clear(char * _array, int length){
    for(int i = 0; i < length; i++){
        _array[i] = 0;
    }
}

void Rotate(char * _array, char * res, int length){
    Clear(res, length);
    for(int _i = length - 1; _i >= 0; _i--){
        for(int i = length - 1, x = 0; i >= 0; i--, x++){
            res[_i] |= ((_array[x] >> _i ) & 1) << i;
        }
    }
}