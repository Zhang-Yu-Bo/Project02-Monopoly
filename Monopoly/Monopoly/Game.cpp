#include "Game.h"

Game::Game(string fileName = "basemap") {
	system("cls");
	cout << fileName;
	Sleep(1000);

	this->mapFileName = fileName;
	system("cls");
	Display::setConsoleCursorCoordinate(0, 0);

	system("mode con cols=220 lines=50");
	Display::printBoard();
	Display::rollDiceAnimate(2);
}