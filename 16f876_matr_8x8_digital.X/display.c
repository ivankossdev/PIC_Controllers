#include "display.h"

char display[4][8] = {
    {0b00000111, 0b00000111, 0b00000111, 0b00000000, 0b00000000, 0b00000111, 0b00000111, 0b00000111},
    {0b00000000, 0b00000000, 0b11110000, 0b00010000, 0b00010000, 0b11110000, 0b00000000, 0b00000000},
    {0b00000000, 0b00000000, 0b00001111, 0b00001000, 0b00001000, 0b00001111, 0b00000000, 0b00000000},
    {0b11100000, 0b11100000, 0b11100000, 0b00000000, 0b00000000, 0b11100000, 0b11100000, 0b11100000},
}; 

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

void MatrixEnableLEDLine(int segment, char data){
    SpiSendByte((char)segment);
    SpiSendByte(data);
}

void ShowSimvolString(int matrSegmentsCount, int sA[]){
    for(int i = 0; i < 8; i++){
        cs = 0;
        for(int _i = matrSegmentsCount; _i >= 0; _i--){
            MatrixEnableLEDLine(i + 1, GetDgigtal(sA[_i])[i]);
        }
        cs = 1;
    }
}

void ShowDisplay(int matrSegmentsCount){
    for(int ledLineMatr = 0; ledLineMatr < 8; ledLineMatr++){
        cs = 0;
        for(int segMatr = matrSegmentsCount; segMatr >= 0; segMatr--){
            /* Цикл передает в матрицу значение массива 
             * display[сегмент матрицы 0 - 3][0 - 7 линейка светодиода] 
             */
            MatrixEnableLEDLine(ledLineMatr + 1, display[segMatr][ledLineMatr]);
        }
        cs = 1;
    }
}