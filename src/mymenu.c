#include <stdio.h>
#include "../include/mymenu.h"

void printMenu(Menu* menu) {
	printf("%s", menu->header);
	printf("\n");
	printf("%s", menu->menuContent);
	printf("\n");
}