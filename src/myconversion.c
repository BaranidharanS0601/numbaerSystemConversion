#include "../include/myconversion.h"

void decimalToOther(int deciNum, char* convertedString, int toBase, char* charSet) {
	int rem;
	char localRetStr[MAX_STR_LEN] = "";
	char tempStr[MAX_STR_LEN];

	if (deciNum == 0) {
		localRetStr[0] = charSet[0];
		localRetStr[1] = NULL_CHAR;
	}

	while (deciNum > 0) {
		rem = deciNum % toBase;
		deciNum = deciNum / toBase;

		tempStr[0] = charSet[rem];
		tempStr[1] = NULL_CHAR;

		catString(tempStr, localRetStr);
		cpyString(localRetStr, tempStr);
	}

	cpyString(convertedString, localRetStr);
}

int power(int a, int b) {
	int result = 1;

	for (int i = 0; i < b; i++) {
		result = result * a;
	}

	return result;
}

int getCharVal(char ch, char* charSet) {
	int len = stringLen(charSet);

	for (int i = 0; i < len; i++) {
		if (ch == charSet[i]) {
			return i; 
		}
	}

	return -1;
}

void otherToDecimal(char* otherStr, int* deciNum, int fromBase, char* charSet) {
	int strLen = stringLen(otherStr);
	int localDeciNum = 0;

	if (charSet[0] == otherStr[0] && 0 == strLen) {
		*deciNum = localDeciNum;
		return;
	}

	for (int i = 0; i < strLen; i++) {
		int charVal = getCharVal(otherStr[strLen - 1 - i], charSet);
		localDeciNum += charVal * (power(fromBase, i));
	}

	*deciNum = localDeciNum;
}