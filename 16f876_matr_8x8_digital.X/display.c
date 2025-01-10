#include "display.h"

char display[MTR_DSP][8] = {
    { 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011 }, // [0]
    { 0b11110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b11110000 }, // [1]
    { 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011 }, // [2]
    { 0b11110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b11110000 }  // [3]
};
/*         [0]          [1]        [2]         [3]
 * [0] 0b00000011, 0b11110000, 0b00000011, 0b11110000,
 * [1] 0b00000011, 0b00110000, 0b00000011, 0b00110000,
 * [2] 0b00000011, 0b00110000, 0b00000011, 0b00110000,
 * [3] 0b00000011, 0b00110000, 0b00000011, 0b00110000,
 * [4] 0b00000011, 0b00110000, 0b00000011, 0b00110000,
 * [5] 0b00000011, 0b00110000, 0b00000011, 0b00110000,
 * [6] 0b00000011, 0b00110000, 0b00000011, 0b00110000,
 * [7] 0b00000011, 0b11110000, 0b00000011, 0b11110000,
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

void InsertShapeInDspArr(char * ar,int cY, int matrSegmant, int arElements){
    for(int i = arElements - 1, j = cY; i >= 0; i--, j--){
        display[matrSegmant][j] |= *(ar + i);
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

void InsertSimvInDspArr(int dig, int cY, int matrSegmant, int arElements){
    switch(dig){
        case 0: InsertShapeInDspArr((char *)simvol_0, cY, matrSegmant, arElements); break;
        case 1: InsertShapeInDspArr((char *)simvol_1, cY, matrSegmant, arElements); break;
        case 2: InsertShapeInDspArr((char *)simvol_2, cY, matrSegmant, arElements); break;
        case 3: InsertShapeInDspArr((char *)simvol_3, cY, matrSegmant, arElements); break;
        case 4: InsertShapeInDspArr((char *)simvol_4, cY, matrSegmant, arElements); break;
        case 5: InsertShapeInDspArr((char *)simvol_5, cY, matrSegmant, arElements); break;
        case 6: InsertShapeInDspArr((char *)simvol_6, cY, matrSegmant, arElements); break;
        case 7: InsertShapeInDspArr((char *)simvol_7, cY, matrSegmant, arElements); break;
        case 8: InsertShapeInDspArr((char *)simvol_8, cY, matrSegmant, arElements); break;
        case 9: InsertShapeInDspArr((char *)simvol_9, cY, matrSegmant, arElements); break;
    }
}