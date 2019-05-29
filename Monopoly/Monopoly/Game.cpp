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

	// 尋找是哪位玩家的回合
	auto playerIter = players.begin();
	vector<Site>::iterator siteIter;
	for (; playerIter != players.end(); playerIter++)
		if (playerIter->playerID == this->whosTurn)
			break;

	while (this->gameLife) {
		if (playerIter == players.end())
			playerIter = players.begin();

		// 玩家行為開始
		if (!playerIter->cannotMove) {//可移動
			playerIter->Move(playerIter->RollADice());//骰骰子並移動
			int currentLocation = playerIter->location;

			//判斷格子類型
			switch (sites[currentLocation].type){
			case START:
				//do nothing for now
				break;
			case ESTATE:
				//若達成買地產條件，詢問是否置產(無主地且玩家現金足夠)
				if (!sites[currentLocation].owner && playerIter->money >= sites[currentLocation].firstPrice) {
					//如果回答yes(尚未實作)
					playerIter->ProchaseAnEstate(currentLocation,sites);
					
				}
				else {//有主地
					//若達成地產升級條件，詢問是否升級(自己地)
					if (sites[currentLocation].owner == playerIter->playerID && sites[currentLocation].estateLevel < 3) {
						playerIter->UpgradeAnEstate(currentLocation, sites);//尚未實作
					}
					//若踩到其他玩家之地產，進行付費(他人地)
					else if (sites[currentLocation].owner != playerIter->playerID) {

					}
				}
				
				break;
			//若踩到機會、命運
			case CHANCE:
				break;
			case FORTUNE:
				break;
			default:
				break;
			}

			

		}
		else {//不可移動
			playerIter->cannotMove--;
		}
		

		// 玩家行為結束

		// 破產判定開始
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
		// 破產判定結束

		// 勝利判定開始
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
		// 勝利判定結束

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
		cout << "檔案開啟失敗，結束程式\n";
		system("pause");
		exit(1);
	}
	else {
		// 地點讀取
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
		// 地點排序開始
		for (int i = 0; i < sites.size() - 1; i++) {
			for (int j = 0; j < sites.size() - 1; j++) {
				if (sites[j].location > sites[j + 1].location) {
					Site temp = sites[j];
					sites[j] = sites[j + 1];
					sites[j + 1] = temp;
				}
			}
		}
		// 地點排序結束

		// ...角色讀取
		players.push_back(Player(0, 0, 0));

		// 角色排序開始
		for (int i = 0; i < players.size()-1; i++) {
			for (int j = 0; j < players.size() - 1; j++) {
				if (players[j].playerID > players[j + 1].playerID) {
					Player temp = players[j];
					players[j] = players[j + 1];
					players[j + 1] = temp;
				}
			}
		}
		// 角色排序結束
		
	}
}

void Game::openOptions() {
	Display::showGameOptions();
	//this->gameLife = false;
	return;
}