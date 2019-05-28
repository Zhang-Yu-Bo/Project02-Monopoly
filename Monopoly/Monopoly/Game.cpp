#include "Game.h"

Game::Game(string fileName = "basemap") {

	system("cls");
	Display::setConsoleCursorCoordinate(0, 0);

	// initial condition
	this->mapFileName = fileName;
	this->gameLife = true;
	this->whosTurn = 0;

	// loading Map from file
	this->loadMap();
}

void Game::start() {
	system("mode con cols=220 lines=50");
	Display::printBoard();
	Display::printRightSpace();
	Display::printCurrentPlayer(1);
	Display::printRound(1);
	system("pause");
	//Display::rollDiceAnimate(2);
}

bool Game::isGameAlive() {
	return this->gameLife;
}

void Game::process() {
	//int command = 0;
	int playerNum = players.size();

	// �M��O���쪱�a���^�X
	auto iterator = players.begin();
	for (; iterator != players.end(); iterator++)
		if (iterator->playerID == this->whosTurn)
			break;

	while (this->gameLife) {
		if (iterator == players.end())
			iterator = players.begin();

		// ���a�欰�}�l

		// ���a�欰����

		// �}���P�w�}�l
		vector<Player> fakePlayers;
		for (auto i = players.begin(); i != players.end(); i++) {
			if (i->money >= 0) {
				fakePlayers.push_back(*i);
			}
			else {

			}
		}
		players = fakePlayers;
		playerNum = players.size();
		if (playerNum == 0) {
			this->gameLife = false;
			return;
		}
		// �}���P�w����

		// �ӧQ�P�w�}�l
		playerNum = players.size();
		if (playerNum == 1) {
			system("cls");
			auto i = players.begin();
			for (; i != players.end(); i++)
				if (i->money >= 0)
					break;
			cout << "Player" << i->playerID << " is winner.\n";
			this->gameLife = false;
			system("pause");
			return;
		}
		// �ӧQ�P�w����

		iterator++;
	}
	/*
	while (command = _getch()) {
		if (command == KEYBOARD_ESCAPE) {
			this->openOptions();
			return;
		}
		else {
			return;
		}
	}
	*/
}

void Game::loadMap() {
	fstream inputFile;
	inputFile.open("Map/" + this->mapFileName + ".txt");

	if (!inputFile) {
		system("cls");
		Display::setConsoleCursorCoordinate();
		cout << "�ɮ׶}�ҥ��ѡA�����{��\n";
		system("pause");
		exit(1);
	}
	else {
		int location, type;
		int firstPrice, tolls, firstTolls, secondTolls, thirdTolls;
		string name;
		inputFile >> mapName;
		inputFile >> remainTurn;
		inputFile >> allPlayers;
		for (int i = 0; i < 28; i++) {
			inputFile >> location >> name >> type;
			if (type == 1) 
			{
				inputFile >> firstPrice >> tolls >> firstTolls >> secondTolls >> thirdTolls;
				Site loadSite(location, name, type, firstPrice, tolls, firstTolls, secondTolls, thirdTolls);
				sites.push_back(loadSite);
			}
			else
			{
				Site loadSite(location, name, type);
				sites.push_back(loadSite);
			}
		}
		players.push_back(Player(0, 0, 0));
	}
}

void Game::openOptions() {
	this->gameLife = false;
	return;
}