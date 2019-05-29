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
	this->openOptions();
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
	auto playerIter = players.begin();
	vector<Site>::iterator siteIter;
	for (; playerIter != players.end(); playerIter++)
		if (playerIter->playerID == this->whosTurn)
			break;

	while (this->gameLife) {
		if (playerIter == players.end())
			playerIter = players.begin();

		// ���a�欰�}�l
		if (!playerIter->cannotMove) {//�i����
			playerIter->Move(playerIter->RollADice());//���l�ò���
			int currentLocation = playerIter->location;

			//�P�_��l����
			switch (sites[currentLocation].type){
			case START:
				//do nothing for now
				break;
			case ESTATE:
				//�Y�F���R�a������A�߰ݬO�_�m��(�L�D�a�B���a�{������)
				if (!sites[currentLocation].owner && playerIter->money >= sites[currentLocation].firstPrice) {
					//�p�G�^��yes(�|����@)
					playerIter->ProchaseAnEstate(currentLocation,sites);
					
				}
				else {//���D�a
					//�Y�F���a���ɯű���A�߰ݬO�_�ɯ�(�ۤv�a)
					if (sites[currentLocation].owner == playerIter->playerID && sites[currentLocation].estateLevel < 3) {
						playerIter->UpgradeAnEstate(currentLocation, sites);//�|����@
					}
					//�Y����L���a���a���A�i��I�O(�L�H�a)
					else if (sites[currentLocation].owner != playerIter->playerID) {

					}
				}
				
				break;
			//�Y�����|�B�R�B
			case CHANCE:
				break;
			case FORTUNE:
				break;
			default:
				break;
			}

			

		}
		else {//���i����
			playerIter->cannotMove--;
		}
		

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

		playerIter++;
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
		// �a�IŪ��
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
		// �a�I�ƧǶ}�l
		for (int i = 0; i < sites.size() - 1; i++) {
			for (int j = 0; j < sites.size() - 1; j++) {
				if (sites[j].location > sites[j + 1].location) {
					Site temp = sites[j];
					sites[j] = sites[j + 1];
					sites[j + 1] = temp;
				}
			}
		}
		// �a�I�Ƨǵ���

		// ...����Ū��
		players.push_back(Player(0, 0, 0));

		// ����ƧǶ}�l
		for (int i = 0; i < players.size()-1; i++) {
			for (int j = 0; j < players.size() - 1; j++) {
				if (players[j].playerID > players[j + 1].playerID) {
					Player temp = players[j];
					players[j] = players[j + 1];
					players[j + 1] = temp;
				}
			}
		}
		// ����Ƨǵ���
		
	}
}

void Game::openOptions() {
	Display::showGameOptions();
	//this->gameLife = false;
	return;
}