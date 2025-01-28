#include "display.h"
#include <string.h>

char display[MTR_DSP][8] = {
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }, // [0]
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }, // [1]
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }, // [2]
    { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }  // [3]
};
/*         [0]          [1]        [2]         [3]
 * [0] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [1] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [2] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [3] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [4] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [5] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [6] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
 * [7] 0b00000000, 0b00000000, 0b00000000, 0b00000000,
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
    for(int matrSegmant = 0; matrSegmant < MTR_DSP; matrSegmant++){
        for(int row = 0; row < 8; row++){
            display[matrSegmant][row] = 0x00; 
        }
    }
}

void ClearDspArrSgm(int seg){
    for(int j = 0; j < 8; j++){
            display[seg][j] = 0x00; 
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

/* Рассчитывает ширину символа */
int GetWidthShapeSegment(char * fig){
    int shift = 0;
    /* Расчет ширины символа */
    while(1){
        for(int i = 0; i < 8; i++){
            if((fig[i] << shift) & 0b10000000) return 8 - shift;
        }
        shift++;
        /* Значение по умолчанию */
        if (shift >= 8) return 5; 
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

void InsertShapeByCord(TCrd *cord, char shape[], int cntArray){
    /* Расчитываем свдиг для установки фигуры в 0 позицию  */
    int setZeroPozition = 8 - GetWidthShapeSegment(shape);
    int tmp = cord->y;
    for(int i = 0; i < cntArray; i++){
        cord->y += i;
        /* Устанавливаем фигуру в 0 поизцию */
        InsertWordByCord(cord, (char)(shape[i] << setZeroPozition));   
        cord->y = tmp;
    }
    
}

void SliceShapeByCordY(char *shape, int position){
    TCrd cord; cord.y = 0, cord.x = MTR_DSP * 8 - 1; 
    int setZeroPozition = 8 - GetWidthShapeSegment(shape);
    char shapePositoin = 0; 
    
    for(int i = 0; i < 8; i++){
        cord.y = i;
        shapePositoin = (char)(shape[i] << setZeroPozition);
        InsertWordByCord(&cord, (shapePositoin << position) & 0b10000000 );   
    }
}

char *GetSimvolArray(char ch){
    char *bufer = calloc(8, sizeof(char));
    switch(ch){
        case '0': bufer = (char *)simvol_0; break;
        case '1': bufer = (char *)simvol_1; break;
        case '2': bufer = (char *)simvol_2; break;
        case '3': bufer = (char *)simvol_3; break;
        case '4': bufer = (char *)simvol_4; break;
        case '5': bufer = (char *)simvol_5; break;
        case '6': bufer = (char *)simvol_6; break;
        case '7': bufer = (char *)simvol_7; break;
        case '8': bufer = (char *)simvol_8; break;
        case '9': bufer = (char *)simvol_9; break;
        case '.': bufer = (char *)simvol_dot; break;
        case ' ': bufer = (char *)simvol_space; break; 
        case ':': bufer = (char *)simvol_d_dot; break;
        case '-': bufer = (char *)simvol_dash; break;
    }
    
    return bufer;
}    

void RunLeftString(char *str){
    int c = 0;
    
    do{
        int width = GetWidthShapeSegment(GetSimvolArray(str[c]));
        for(int i = 0; i <= width; i++){
            SliceShapeByCordY(GetSimvolArray(str[c]), i);
            ShowDisplay();
            __delay_ms(100);
            ShiftLeftOneBit();
        }
        c++;
    }while(str[c] != '\0');
}