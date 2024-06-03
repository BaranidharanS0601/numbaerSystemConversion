#include <stdio.h>
#include "../include/myconversion.h"

int main() {
	printf("Testing myconversion.h\n\n");

	int decimal = 78;
	char binary[MAX_STR_LEN] = EMPTY_STR;
	char octal[MAX_STR_LEN] = EMPTY_STR;
	char hexadecimal[MAX_STR_LEN] = EMPTY_STR;

	decimalToOther(decimal, binary, 2, BIN_CHAR_SET);
	decimalToOther(decimal, octal, 8, OCT_CHAR_SET);
	decimalToOther(decimal, hexadecimal, 16, HEX_CHAR_SET);

	printf("decimal: %d\n", decimal);
	printf("binary: %s\n", binary);
	printf("octal: %s\n", octal);
	printf("hexadecimal: %s\n\n", hexadecimal);

	printf("3 power 2: %d\n\n", power(3, 2));

	printf("D value in hexadecimal is %d\n\n", getCharVal('D', HEX_CHAR_SET));

	int deciNum1;
	int deciNum2;
	int deciNum3;
	char* binaryIn = "10011010";
	char* octalIn = "232";
	char* hexaIn = "9A";

	otherToDecimal(binaryIn, &deciNum1, 2, BIN_CHAR_SET);
	otherToDecimal(octalIn, &deciNum2, 8, OCT_CHAR_SET);
	otherToDecimal(hexaIn, &deciNum3, 16, HEX_CHAR_SET);

	printf("decimal: %d\n", deciNum1);
	printf("binary: %s\n", binaryIn);
	printf("decimal: %d\n", deciNum2);
	printf("octal: %s\n", octalIn);
	printf("decimal: %d\n", deciNum3);
	printf("hexadecimal: %s\n\n", hexaIn);

	printf("Test passed!");

	return 0;
}