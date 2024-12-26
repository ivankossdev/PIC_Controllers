#include "shape.h"

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

void MatrixSpiSendWord(int segment, char data){
    SpiSendByte((char)segment);
    SpiSendByte(data);
}

void ShowSimvolString(int matrSegmentsCount, int sA[]){
    for(int i = 0; i < 8; i++){
        cs = 0;
        for(int _i = matrSegmentsCount; _i >= 0; _i--){
            MatrixSpiSendWord(i + 1, GetDgigtal(sA[_i])[i]);
        }
        cs = 1;
    }
}