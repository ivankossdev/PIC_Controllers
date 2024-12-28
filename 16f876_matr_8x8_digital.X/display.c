#include "display.h"

char display[MTR_DSP][8] = {'\0'};

void MatrixEnableLEDLine(int segment, char data){
    SpiSendByte((char)segment);
    SpiSendByte(data);
}


void ClearDisplay(void){
    for(int i = 0; i < 8; i++){
        cs = 0;
        for(int _i = MTR_DSP; _i >= 0; _i--){
            MatrixEnableLEDLine(i + 1, 0x00);
        }
        cs = 1;
    }
}

void ShowDisplay(void){
    for(int ledLineMatr = 0; ledLineMatr < 8; ledLineMatr++){
        cs = 0;
        for(int segMatr = MTR_DSP; segMatr >= 0; segMatr--){
            /* Цикл передает в матрицу значение массива 
             * display[сегмент матрицы 0 - 3][0 - 7 линейка светодиода] 
             */
            MatrixEnableLEDLine(ledLineMatr + 1, display[segMatr][ledLineMatr]);
        }
        cs = 1;
    }
}

void InsertInDisplayArray(char * ar,int cY, int cX, int arElements){
    for(int i = 0, j = cY; i < arElements; i++, j--){
        display[cX][j] |= *(ar + i);
    }
}

void ClearDisplayArray(void){
    for(int i = 0; i < MTR_DSP; i++){
        for(int j = 0; j < 8; j++){
            display[i][j] = 0x00; 
        }
    }
}

void Reverse(char * arrFnt, char * revArrFnt, int countElemntArray)
{
    for(int i = 0, j = countElemntArray - 1; i < j; i++, j--)
    {
        char t = arrFnt[i];
        revArrFnt[i] = arrFnt[j];
        revArrFnt[j] = t;
    }  
}

void NoNameDgFn(int dig, int cY, int cX, int arElements){
    char * revArray = calloc((size_t)arElements, sizeof(char));
    
    switch(dig){
        case 0: Reverse((char *)simvol_0, revArray, arElements); InsertInDisplayArray((char *)revArray, cY, cX, arElements); break;
        case 1: Reverse((char *)simvol_1, revArray, arElements); InsertInDisplayArray((char *)revArray, cY, cX, arElements); break;
        case 2: Reverse((char *)simvol_2, revArray, arElements); InsertInDisplayArray((char *)revArray, cY, cX, arElements); break;
        case 3: Reverse((char *)simvol_3, revArray, arElements); InsertInDisplayArray((char *)revArray, cY, cX, arElements); break;
        case 4: Reverse((char *)simvol_4, revArray, arElements); InsertInDisplayArray((char *)revArray, cY, cX, arElements); break;
        case 5: Reverse((char *)simvol_5, revArray, arElements); InsertInDisplayArray((char *)revArray, cY, cX, arElements); break;
    }
    free(revArray);
}

//    display[0][7] = 0xff; // y = 0, x = 0
//    display[1][6] = 0xff; // y = 1, x = 8 
//    display[2][5] = 0xff; // y = 2, x = 16 
//    display[3][4] = 0xff; // y = 3, x = 24
//    
//    display[3][3] = 0xff; 
//    display[2][2] = 0xff; 
//    display[1][1] = 0xff; 
//    display[0][0] = 0xff; 