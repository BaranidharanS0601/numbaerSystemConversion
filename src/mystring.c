#include "../include/mystring.h"

int stringLen(char* str) {
	int len = 0;

	while (str[len] != NULL_CHAR) {
		len++;
	}

	return len;
}

void catString(char* str1, char* str2){
	int lenStr1 = stringLen(str1);
	int lenStr2 = stringLen(str2);

	for (int i = 0; i < lenStr2; i++){
		str1[lenStr1 + i] = str2[i];
	}

	str1[lenStr1 + lenStr2] = NULL_CHAR;
}

void cpyString(char* desStr, char* srcStr) {
	int lenSrcStr = stringLen(srcStr);

	for (int i = 0; i < lenSrcStr; i++) {
		desStr[i] = srcStr[i];
	}

	desStr[lenSrcStr] = '\0';
}