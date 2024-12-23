#include "matrix.h"

/******pic 16f876******
 * pin  7 RA5 -> CS   *
 * pin 14 RC3 -> CLK  *
 * pin 16 RC5 -> DIN  *
 **********************/

/* ������� ������� */
void MatrixClear (void)
{
  char i = 8;
  do
  {
    MatrixSendToSegment(i, 0x00); 
  } while (--i);
}

/* ������������� ������� c ������������ 7219*/
void MatrixInit(void) {
    __delay_ms(100);
    cs=1; 
    MatrixSendToSegment(0x09, 0x00);  
    MatrixSendToSegment(0x0b, 0x07); 
    MatrixSendToSegment(0x0A, 0x02); 
    MatrixSendToSegment(0x0c, 0x01); 
    MatrixClear();
}

/* ���������� ������ 0 - 0xff � ��������� ������� �������� 7219
 * char rg ������� (������) ����������
 * char dt ����� ������� �������� � ������� (������)
 */
void MatrixSendToSegment(int segment, char data) {
    cs = 0;
    SpiSendByte((char)segment);
    SpiSendByte(data);
    cs = 1;
}
