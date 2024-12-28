#include "display.h"

char display[4][8] = {'\0'};

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

//    display[0][7] = 0xff; // y = 0, x = 0
//    display[1][6] = 0xff; // y = 1, x = 8 
//    display[2][5] = 0xff; // y = 2, x = 16 
//    display[3][4] = 0xff; // y = 3, x = 24
//    
//    display[3][3] = 0xff; 
//    display[2][2] = 0xff; 
//    display[1][1] = 0xff; 
//    display[0][0] = 0xff; 