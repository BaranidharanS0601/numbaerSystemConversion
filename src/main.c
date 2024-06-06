#include <stdio.h>
#include <stdlib.h>
#include "../include/mymenu.h"
#include "../include/mystring.h"
#include "../include/myconversion.h"

#define HEADER "\
	NUMBER SYTEM CONVERSION\n\
 	------ ----- ----------\n"
#define MAIN_MENU_CONTENT "\
	(1) Binary to Decimal.\n\
	(2) Octal to Decimal.\n\
	(3) Hexadecimal to Decimal.\n\
	(4) Decimal to Binary.\n\
	(5) Decimal to Octal.\n\
	(6) Decimal to Hexadecimal.\n\
	(7) Other Options.\n\
	(8) Instructions.\n\
	(q) Quit\n"
#define BIN_TO_DEC_MENU "\
	Binary to Decimal:\n\n\
	# Input Example\n\
	# Enter Binary string: 1000001\n"
#define OCT_TO_DEC_MENU "\
	Octal to Decimal:\n\n\
	# Input Example\n\
	# Enter Octal string: 102\n"
#define HEX_TO_DEC_MENU "\
	Hexadecimal to Decimal:\n\n\
	# Input Example\n\
	# Enter Hexadecimal string: 42\n"
#define DEC_TO_BIN_MENU "\
	Decimal to Binary:\n\n\
	# Input Example\n\
	# Enter Decimal Number: 66\n"
#define DEC_TO_OCT_MENU "\
	Decimal to Octal:\n\n\
	# Input Example\n\
	# Enter Decimal Number: 66\n"
#define DEC_TO_HEX_MENU "\
	Decimal to Hexadecimal:\n\n\
	# Input Example\n\
	# Enter Decimal Number: 66\n"
#define OTHER_OPTIONS_MENU "\
	(1)Binary to Octal.\n\
	(2)Binary to Hexadecimal.\n\
	(3)Octal to Binary.\n\
	(4)Octal to Hexadecimal.\n\
	(5)Hexadecimal to Binary.\n\
	(6)Hexadecimal to Octal.\n\
	(0)Go to Main Menu.\n"
#define INSTRUCTION "\
	#pending\n"

int getOption();
void pressEnterToContinue();
void clearScreen();

void binToDec();
void octToDec();
void hexToDec();
void decToBin();
void decToOct();
void decToHex();

int main(int argv, char** argc) {
	
	/* Initalizing all menus */
	Menu mainMenu = {HEADER, MAIN_MENU_CONTENT};
	Menu binToDecMenu = {HEADER, BIN_TO_DEC_MENU};
	Menu octToDecMenu = {HEADER, OCT_TO_DEC_MENU};
	Menu hexToDecMenu = {HEADER, HEX_TO_DEC_MENU};
	Menu decToBinMenu = {HEADER, DEC_TO_BIN_MENU};
	Menu decToOctMenu = {HEADER, DEC_TO_OCT_MENU};
	Menu decToHexMenu = {HEADER, DEC_TO_HEX_MENU};
	Menu otherOtionsMenu = {HEADER, OTHER_OPTIONS_MENU};
	Menu instructionMenu = {HEADER, INSTRUCTION};

	int True = 1;

	int option = 0;

	while (True) {

		clearScreen();
		
		switch (option) {
		case 0:
			printMenu(&mainMenu);
			printf("	Enter valid option: ");
			option = getOption();
			break;
		case 1:
			printMenu(&binToDecMenu);
			binToDec();
			pressEnterToContinue();
			option = 0;
			break;
		case 2:			
			printMenu(&octToDecMenu);
			octToDec();
			pressEnterToContinue();
			option = 0;
			break;
		case 3:
			printMenu(&hexToDecMenu);
			hexToDec();
			pressEnterToContinue();
			option = 0;
			break;
		case 4:
			printMenu(&decToBinMenu);
			decToBin();
			pressEnterToContinue();
			option = 0;
			break;
		case 5:
			printMenu(&decToOctMenu);
			decToOct();
			pressEnterToContinue();
			option = 0;
			break;
		case 6:
			printMenu(&decToHexMenu);
			decToHex();
			pressEnterToContinue();
			option = 0;
			break;
		case 7:
			printMenu(&otherOtionsMenu);
			pressEnterToContinue();
			option = 0;
			break;
		case 8:
			printMenu(&instructionMenu);
			pressEnterToContinue();
			option = 0;
			break;
		case 9:
			True = 0;
			break;
		default:
			pressEnterToContinue();
			option = 0;
			break;
		}
	}	

	return 0;
}

int getOption() {
	char opt;
	int retOpt = 0;
	char validOpt[] = "012345678q";
	int len = sizeof(validOpt) / sizeof(validOpt[0]);

	scanf("%c", &opt);
	getchar();

	for (int i = 0; i < len; i++) {
		if (opt == validOpt[i]) {
			retOpt = i;
		}
	}

	return retOpt;

}

void pressEnterToContinue() {
    printf("	Press ENTER to continue...");
    while (getchar() != '\n');
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void binToDec() {
	char inp[MAX_STR_LEN];
	int retNum;
	
	printf("	Enter Binary string: ");
	scanf("%s", inp);
	getchar();
	
	otherToDecimal(inp, &retNum, 2, BIN_CHAR_SET);

	printf("	Decimal Equivalent: %d\n\n", retNum);
}

void octToDec() {
	char inp[MAX_STR_LEN];
	int retNum;
	
	printf("	Enter Octal string: ");
	scanf("%s", inp);
	getchar();
	
	otherToDecimal(inp, &retNum, 8, OCT_CHAR_SET);

	printf("	Decimal Equivalent: %d\n\n", retNum);
}

void hexToDec() {
	char inp[MAX_STR_LEN];
	int retNum;
	
	printf("	Enter Hexadecimal string: ");
	scanf("%s", inp);
	getchar();
	
	otherToDecimal(inp, &retNum, 16, HEX_CHAR_SET);

	printf("	Decimal Equivalent: %d\n\n", retNum);
}

void decToBin() {
	int inp;
	char retStr[MAX_STR_LEN];

	printf("	Enter Decimal Number: ");
	scanf("%d", &inp);
	getchar();

	decimalToOther(inp, retStr, 2, BIN_CHAR_SET);

	printf("	Binary Equivalent: %s\n\n", retStr);
}

void decToOct() {
	int inp;
	char retStr[MAX_STR_LEN];

	printf("	Enter Decimal Number: ");
	scanf("%d", &inp);
	getchar();

	decimalToOther(inp, retStr, 8, OCT_CHAR_SET);

	printf("	Octal Equivalent: %s\n\n", retStr);
}

void decToHex() {
	int inp;
	char retStr[MAX_STR_LEN];

	printf("	Enter Decimal Number: ");
	scanf("%d", &inp);
	getchar();

	decimalToOther(inp, retStr, 16, HEX_CHAR_SET);

	printf("	Hexadecimal Equivalent: %s\n\n", retStr);
}
