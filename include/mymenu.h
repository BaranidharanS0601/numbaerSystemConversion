#ifndef MYMENU_H
#define MYMENU_H

typedef struct menu {
	char* header;
	char* menuContent;
}Menu;

void printMenu(Menu* menu);

#endif