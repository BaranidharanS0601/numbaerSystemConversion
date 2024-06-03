#ifndef MYCONVERSION_H
#define MYCONVERSION_H 

#include "mystring.h"

#define BIN_CHAR_SET "01"
#define OCT_CHAR_SET "01234567"
#define HEX_CHAR_SET "0123456789ABCDE"

void decimalToOther(int deciNum, char* convertedString, int toBase, char* charSet);
int power(int a, int b);
int getCharVal(char ch, char* charSet);
void otherToDecimal(char* otherStr, int* deciNum, int fromBase, char* charSet);

#endif // MYCONVERSION_H