#include "Game.h"

Game::Game(string fileName = "basemap") {

	system("cls");
	Display::setConsoleCursorCoordinate(0, 0);

	// initial condition
	this->mapFileName = fileName;
	this->life = true;
	this->playerState = 0;

	// loading Map from file
	this->loadMap();
}

void Game::start() {
	system("mode con cols=220 lines=50");
	Display::printBoard();
	Display::printRightSpace();
	Display::printCurrentPlayer(1);
	Display::printRound(1);
	Display::rollDiceAnimate(2);
}

bool Game::isGameAlive() {
	return this->life;
}

void Game::process() {
	int command = 0;
	while (command = _getch()) {
		if (command == KEYBOARD_ESCAPE) {
			this->openOptions();
			return;
		}
		else {
			return;
		}
	}
}

void Game::loadMap() {
	fstream inputFile;
	inputFile.open("Map/" + this->mapFileName + ".txt");

	if (!inputFile) {
		system("cls");
		Display::setConsoleCursorCoordinate();
		cout << "檔案開啟失敗，結束程式\n";
		system("pause");
		exit(1);
	}
	else {
		// ...開始讀檔
	}
}

void Game::openOptions() {
	//this->life = false;
	Display::showGameOptions();
	return;
}