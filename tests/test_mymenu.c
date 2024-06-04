#include <stdio.h>
#include "../include/mymenu.h"

#define HEADER "	NUMBER SYTEM CONVERSION\n 	~~~~~~ ~~~~~ ~~~~~~~~~~\n"
#define MAIN_MENU_CONTENT "\
	(1) Binary to Decimal.\n\
	(2) Octal to Decimal.\n\
	(3) Hexadecimal to Decimal.\n\
	(4) Decimal to Binary.\n\
	(5) Decimal to Octal.\n\
	(6) Decimal to Hexadecimal.\n\
	(7) Other Options.\n\
	(8) Instructions. // optional\n\
	(q) Quit\n"

int main() {
	printf("TEsting mymenu.h\n\n");

	Menu mainMenu = {HEADER, MAIN_MENU_CONTENT};

	printMenu(&mainMenu);

	printf("test passed!!");


	return 0;
}