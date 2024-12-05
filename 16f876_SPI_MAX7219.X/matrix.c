#include "matrix.h"

/******pic 16f876******
 * pin  7 RA5 -> CS   *
 * pin 14 RC3 -> CLK  *
 * pin 16 RC5 -> DIN  *
 **********************/

/* Очистка матрицы */
void SpiClearMatrix (void)
{
  char i = 8;
  do
  {
    SendToSegment(i, 0x00); 
  } while (--i);
}

/* Инициализация матрицы c контроллером 7219*/
void MatrixInit(void) {
    __delay_ms(100);
    cs=1; 
    SendToSegment(0x09, 0x00);  
    SendToSegment(0x0b, 0x07); 
    SendToSegment(0x0A, 0x02); 
    SendToSegment(0x0c, 0x01); 
    SpiClearMatrix();
}

/* Отправляет данные 0 - 0xff в выбранный регистр драйвера 7219
 * char rg регистр (разряд) микросхемы
 * char dt данне которые передаем в регистр (разряд)
 */
void SendToSegment(int segment, char data) {
    cs = 0;
    SpiSendByte(segment);
    SpiSendByte(data);
    cs = 1;
}
