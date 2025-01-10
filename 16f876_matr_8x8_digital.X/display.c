#include "display.h"

char display[MTR_DSP][8] = {
    { 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011 }, // [0]
    { 0b11110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b11110000 }, // [1]
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }, // [2]
    { 0b00000001, 0b00000001, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11000000, 0b11000000 }, // [3]
};
/*         [0]          [1]        [2]         [3]
 * [0] 0b00000011, 0b11110000, 0b00000000, 0b00000001,
 * [1] 0b00000011, 0b00110000, 0b00000000, 0b00000001,
 * [2] 0b00000011, 0b00110000, 0b00000000, 0b00000000,
 * [3] 0b00000011, 0b00110000, 0b00000000, 0b00000000,
 * [4] 0b00000011, 0b00110000, 0b00000000, 0b00000000,
 * [5] 0b00000011, 0b00110000, 0b00000000, 0b00000000,
 * [6] 0b00000011, 0b00110000, 0b00000000, 0b11000000,
 * [7] 0b00000011, 0b11110000, 0b00000000, 0b11000000,
 */

char ReverseChar(char ch){
    char rv = 0;
    for(int i = 0, t = 7; i < 8; i++, t--){
        rv |= ((ch >> i) & 0x01) << t;
    }
    
    return rv;
}

void MatrixEnableLEDLine(int segment, char data){
    data = ReverseChar(data);
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
    for(int ledColumn = 0, ledLine = 8; ledColumn < 8; ledColumn++, ledLine--){
        
        cs = 0;
        for(int segMatr = MTR_DSP; segMatr >= 0; segMatr--){
            /* Цикл передает в матрицу значение массива 
             * display[сегмент матрицы [1 - 4][0 - 7 линейка светодиода] 
             */
            
            MatrixEnableLEDLine(ledLine, display[segMatr][ledColumn]);
        }
        cs = 1;
    }
}

void InsertShapeInDspArr(char * ar,int cY, int cX, int arElements){
    for(int i = 0, j = cY; i < arElements; i++, j--){
        display[cX][j] |= *(ar + i);
    }
}

void ClearDspArr(void){
    for(int i = 0; i < MTR_DSP; i++){
        for(int j = 0; j < 8; j++){
            display[i][j] = 0x00; 
        }
    }
}

void ClearDspArrSgm(int seg){
    for(int j = 0; j < 8; j++){
            display[seg][j] = 0x00; 
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

void InsertSimvInDspArr(int dig, int cY, int cX, int arElements){
    char * revArray = calloc((size_t)arElements, sizeof(char));
    
    switch(dig){
        case 0: Reverse((char *)simvol_0, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 1: Reverse((char *)simvol_1, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 2: Reverse((char *)simvol_2, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 3: Reverse((char *)simvol_3, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 4: Reverse((char *)simvol_4, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 5: Reverse((char *)simvol_5, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 6: Reverse((char *)simvol_6, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 7: Reverse((char *)simvol_7, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 8: Reverse((char *)simvol_8, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
        case 9: Reverse((char *)simvol_9, revArray, arElements); InsertShapeInDspArr((char *)revArray, cY, cX, arElements); break;
    }
    free(revArray);
}