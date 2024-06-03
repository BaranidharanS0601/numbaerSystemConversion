#ifndef MYSTRING_H
#define MYSTRING_H

#define MAX_STR_LEN 257
#define NULL_CHAR '\0'
#define EMPTY_STR ""

int stringLen(char* str);
void catString(char* str1, char* str2);
void cpyString(char* desStr, char* srcStr);

#endif // MYSTRING_H