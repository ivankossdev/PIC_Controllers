# 1 "font.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/xc8/v2.50/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "font.c" 2
# 1 "./font.h" 1
# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/stdlib.h" 1 3



# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v2.50/pic/include/c99/stdlib.h" 2 3





# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/features.h" 1 3
# 11 "/opt/microchip/xc8/v2.50/pic/include/c99/stdlib.h" 2 3
# 21 "/opt/microchip/xc8/v2.50/pic/include/c99/stdlib.h" 3
# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 1 3
# 24 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef long int wchar_t;
# 128 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef unsigned size_t;
# 174 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef __int24 int24_t;
# 210 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 22 "/opt/microchip/xc8/v2.50/pic/include/c99/stdlib.h" 2 3

int atoi (const char *);
long atol (const char *);



double atof (const char *);


float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);





unsigned long __strtoxl(const char * s, char ** endptr, int base, char is_signed);
# 55 "/opt/microchip/xc8/v2.50/pic/include/c99/stdlib.h" 3
int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));







__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);




typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;




div_t div (int, int);
ldiv_t ldiv (long, long);




typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 2 "./font.h" 2

extern const char simvol_0[8];
extern const char simvol_1[8];
extern const char simvol_2[8];
extern const char simvol_3[8];
extern const char simvol_4[8];
extern const char simvol_5[8];
extern const char simvol_6[8];
extern const char simvol_7[8];
extern const char simvol_8[8];
extern const char simvol_9[8];
extern const char simvol_d_dot[8];
extern const char simvol_space[8];
extern const char simvol_dot[8];
extern const char simvol_dash[8];

char * Copy(char * _array, int length );
char * GetSimvolArray(int num);
# 2 "font.c" 2


const char simvol_0[8] = {0x0e, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0e, 0x00};
const char simvol_1[8] = {0x04, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x0e, 0x00};
const char simvol_2[8] = {0x0e, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1f, 0x00};
const char simvol_3[8] = {0x1f, 0x02, 0x04, 0x02, 0x01, 0x11, 0x0e, 0x00};
const char simvol_4[8] = {0x02, 0x06, 0x0a, 0x12, 0x1f, 0x02, 0x02, 0x00};
const char simvol_5[8] = {0x1f, 0x10, 0x1e, 0x01, 0x01, 0x11, 0x0e, 0x00};
const char simvol_6[8] = {0x06, 0x08, 0x10, 0x1e, 0x11, 0x11, 0x0e, 0x00};
const char simvol_7[8] = {0x1f, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08, 0x00};
const char simvol_8[8] = {0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x0e, 0x00};
const char simvol_9[8] = {0x0e, 0x11, 0x11, 0x0f, 0x01, 0x02, 0x0c, 0x00};
const char simvol_d_dot[8] = {0x00, 0x0c, 0x0c, 0x00, 0x0c, 0x0c, 0x00, 0x00};
const char simvol_space[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const char simvol_dot[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00};
const char simvol_dash[8] = {0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00 };

char * Copy(char * _array, int length ){

    char * res = malloc((size_t)length * sizeof(char));

    for(int i = 0; i < length; i++){
        res[i] = _array[i];
    }
    return res;
}

char * GetSimvolArray(int num){
 char * simvol = malloc(8 * sizeof(char));

 switch(num){
  case 0: simvol = Copy((char * )simvol_0, 8); break;
  case 1: simvol = Copy((char * )simvol_1, 8); break;
  case 2: simvol = Copy((char * )simvol_2, 8); break;
  case 3: simvol = Copy((char * )simvol_3, 8); break;
  case 4: simvol = Copy((char * )simvol_4, 8); break;
  case 5: simvol = Copy((char * )simvol_5, 8); break;
  case 6: simvol = Copy((char * )simvol_6, 8); break;
  case 7: simvol = Copy((char * )simvol_7, 8); break;
  case 8: simvol = Copy((char * )simvol_8, 8); break;
  case 9: simvol = Copy((char * )simvol_9, 8); break;
  default: * simvol = 0xff;
 }

    return simvol;
}
