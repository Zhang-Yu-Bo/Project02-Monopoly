#include "MainMenu.h"
#include <iostream>

using namespace std;

int main(void) {
	MainMenu menu;
	Display::printBoard();
	Display::rollDiceAnimate(2);
	system("pause");
	return 0;
}