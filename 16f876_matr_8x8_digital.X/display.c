#include "display.h"

char display[MTR_DSP][8] = {
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }, // [0]
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }, // [1]
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }, // [2]
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }  // [3]
};
/*         [0]          [1]        [2]         [3]
 * [0] 0b00110000, 0b00000000, 0b00000011, 0b11110000,
 * [1] 0b11110000, 0b00000000, 0b00000011, 0b00110000,
 * [2] 0b11110000, 0b00000000, 0b00000011, 0b00110000,
 * [3] 0b00111110, 0b00000000, 0b00000011, 0b00110000,
 * [4] 0b00111110, 0b00000000, 0b00000011, 0b00110000,
 * [5] 0b11110000, 0b00000000, 0b00000011, 0b00110000,
 * [6] 0b11110000, 0b00000000, 0b00000011, 0b00110000,
 * [7] 0b00110000, 0b00000000, 0b00000011, 0b11110000,
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

void InsertShapeInSegment(char *ar, int matrSegmant, int arElements){
    for(int i = arElements - 1, j = 7; i >= 0; i--, j--){
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

void InsertSimvInSegment(int dig, int matrSegmant, int arElements){
    switch(dig){
        case 0: InsertShapeInSegment((char *)simvol_0, matrSegmant, arElements); break;
        case 1: InsertShapeInSegment((char *)simvol_1, matrSegmant, arElements); break;
        case 2: InsertShapeInSegment((char *)simvol_2, matrSegmant, arElements); break;
        case 3: InsertShapeInSegment((char *)simvol_3, matrSegmant, arElements); break;
        case 4: InsertShapeInSegment((char *)simvol_4, matrSegmant, arElements); break;
        case 5: InsertShapeInSegment((char *)simvol_5, matrSegmant, arElements); break;
        case 6: InsertShapeInSegment((char *)simvol_6, matrSegmant, arElements); break;
        case 7: InsertShapeInSegment((char *)simvol_7, matrSegmant, arElements); break;
        case 8: InsertShapeInSegment((char *)simvol_8, matrSegmant, arElements); break;
        case 9: InsertShapeInSegment((char *)simvol_9, matrSegmant, arElements); break;
    }
}

void ShifRightOneBit(void){
    int row = 0; 
    char shiftBuffer[MTR_DSP] = {'\0'};
    /* Читаем построчно и сдвигаем на 1 бит */
    do{
        /* Сдвиг вправо, сохраняем bit[0] в буфер */
        for(int i = 0; i <  MTR_DSP; i++){
            shiftBuffer[i] = display[i][row] & 0x01; 
            display[i][row] =  display[i][row] >> 1; 
        }
        
        /* Вставляем bit[0] в следующий сегмент, в bit[7] */
        for(int column = 0; column <  MTR_DSP; column++ ){
            if((column + 1) < MTR_DSP) 
                display[column + 1][row] |= shiftBuffer[column] << 7;
        }
        
        row++;
    }while(row < 8);
}

void ShiftLeftOneBit(void){
    int row = 7;
    char shiftBuffer[MTR_DSP] = {'\0'};
    /* Читаем построчно и сдвигаем на 1 бит c 7 байта (count 7) в массиве*/
    do{
        /* Сдвиг влево, сохраняем bit[7] в буфер */
        for(int i = 0; i <  MTR_DSP; i++){
            shiftBuffer[i] = display[i][row] & 0b10000000;
            display[i][row] = (char)(display[i][row] << 1);
        }
        
        /* Вставляем bit[7] в следующий сегмент, в bit[0] */
        for(int column = MTR_DSP - 1; column >=1  ; column--){
                display[column - 1][row] |= shiftBuffer[column] >> 7;
        }
        
    }while(row--);
}

int GetWidthShapeSegment(unsigned char * fig){
    int shift = 0;
    while(1){
        for(int i = 0; i < 8; i++){
            if((fig[i] << shift) & 0b10000000) return 8 - shift;
        }
        shift++;
    }
}

void InsertWordByCord(TCrd *cord, char word){
    /* Переменная column сегмент матрицы */
    int column = 0; char buffer = 0;
    
    if(cord->x < 8) {
        buffer = (char)(word << (8 - cord->x));
        display[column][cord->y] |= word >> cord->x; 
        display[column + 1][cord->y] |= buffer;
    }
    else if(cord->x >= 8 && cord->x < 16){
        buffer = (char)(word << (16 - cord->x));
        display[column + 1][cord->y] |= word >> (cord->x - 8); 
        display[column + 2][cord->y] |= buffer;
    }
    else if(cord->x >= 16 && cord->x < 24){
        buffer = (char)(word << (24 - cord->x));
        display[column + 2][cord->y] |= word >> (cord->x - 16);
        display[column + 3][cord->y] |= buffer;
    }
    else if(cord->x >= 24 && cord->x < 32){
        display[column + 3][cord->y] |= word >> (cord->x - 24);
    }
}

/*  y    x [0]          [1]        [2]         [3]
 * [0] 0b11000000, 0b00000000, 0b00000000, 0b00000000, (y=0 x=0) (y=0 x=1)
 * [1] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [2] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [3] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [4] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [5] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [6] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [7] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 */