#include "MainMenu.h"
#include <iostream>

using namespace std;

int main(void) {
	system("mode con cols=220 lines=50");
	MainMenu menu;
	Display::printBoard();
	Display::rollDiceAnimate(2);
	system("pause");
	return 0;
}