#include <stdio.h>
#include "../include/mystring.h"

int main() {
	printf("Testing mystring.h\n\n");

	char s1[MAX_STR_LEN] = "hello";
	char s2[MAX_STR_LEN] = "world!!";
	char s3[MAX_STR_LEN] = EMPTY_STR;

	int lenS1 = stringLen(s1);
	int lenS2 = stringLen(s2);
	int lenS3 = stringLen(s3);

	printf("len of s1: %d\n", lenS1);
	printf("len of s2: %d\n", lenS2);
	printf("len of s3: %d\n", lenS3);

	catString(s1, s2);
	printf("s1: %s\n", s1);

	printf("s2: %s\n", s2);

	cpyString(s3, s1);
	printf("s3: %s\n", s3);

	printf("Test passed!\n\n");
	return 0;
}