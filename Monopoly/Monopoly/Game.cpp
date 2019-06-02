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
	//system("color 70");
	Display::setColor();
	system("mode con cols=220 lines=50");
	Display::printBoard();
	Display::printRightSpace(allPlayers);
	Display::printCurrentPlayer(whosTurn + 1);
	Display::printRound(remainTurn);
	Display::printEstate(sites);
	Display::printPlayersStatus(players);
	Display::printPlayerStep(players);
	for (int i = 0; i < 28; i++) {
		if (sites[i].owner != -1)
			Display::printOwnEstate(sites[i], players);
	}
	//this->openOptions();
	//system("pause");
	//Display::rollDiceAnimate(2);
}

bool Game::isGameAlive() {
	return this->gameLife;
}

void Game::process() {
	int playerNum = players.size();
	int commandPress = 0;

	// 尋找是哪位玩家的回合
	auto playerIter = players.begin();
	vector<Site>::iterator siteIter;

	playerIter = players.begin() + (this->whosTurn % this->players.size());

	while (this->gameLife) {

		//Display::setConsoleCursorCoordinate(144, 26);
		//cout << "這是測試";
		//Display::setConsoleCursorCoordinate(210, 40);
		//cout << "０";

		// 全畫面更新
		Display::printRightSpace(allPlayers);
		Display::printCurrentPlayer(whosTurn + 1);
		Display::printRound(remainTurn);
		Display::printEstate(sites);
		Display::printPlayersStatus(players);
		Display::printPlayerStep(players);
		for (int i = 0; i < 28; i++) {
			if (sites[i].owner != -1)
				Display::printOwnEstate(sites[i], players);
		}
		Display::clearPlayLog();

		// 玩家行為開始
		if (!playerIter->cannotMove) {//可移動(回合沒被跳過)

			if (!playerIter->barrier || !playerIter->controlledDice) {//擁有道具的情況
				//詢問並顯示是否使用道具
				//路障:剩餘數量N
				//playerIter->PlaceABarrier(playerIter->location,sites);
				//遙控骰子:剩餘數量N
				//請輸入欲擲出點數
			}

			cout << "請按任意鍵骰動骰子．．．";
			while (commandPress = _getch()) {
				if (commandPress == KEYBOARD_ESCAPE) {
					this->openOptions();
				}
				else {
					break;
				}
			}

			int point = playerIter->RollADice();
			// 顯示骰子動畫
			Display::rollDiceAnimate(point);
			Display::clearPlayLog();
			cout << "現在骰到了 " << point;
			Display::setConsoleCursorCoordinate(144, 27);
			cout << "玩家 " << playerIter->playerID + 1 << "從【" << sites[playerIter->location].name << "】";
			Display::setConsoleCursorCoordinate(144, 28);
			cout << "移動到";

			playerIter->Move(point, sites);					// 移動玩家
			int currentLocation = playerIter->location;

			Display::setConsoleCursorCoordinate(150, 28);
			cout << "【" << sites[currentLocation].name << "】";
			Display::printPlayerStep(players);

			//判斷格子類型
			switch (sites[currentLocation].type) {
			case START:
				//do nothing for now
				break;
			case ESTATE:
				if (sites[currentLocation].owner == -1) {//無主地
					if (playerIter->money >= sites[currentLocation].firstPrice) {//若達成買地產條件，詢問是否置產(玩家現金足夠)
						Display::setConsoleCursorCoordinate(144, 30);
						cout << "【" << sites[currentLocation].name << "】目前沒有地主，想成為它（她）的主人嗎?(y/n)：";
						char temp;
						cin >> temp;
						if (temp == 'y' || temp == 'Y') {
							playerIter->ProchaseAnEstate(currentLocation, sites);
							Display::setConsoleCursorCoordinate(144, 31);
							cout << "你成為了【" << sites[currentLocation].name << "】的master，恭喜你";
							for (int i = 0; i < 28; i++) {
								if (sites[i].owner != -1)
									Display::printOwnEstate(sites[i], players);
							}
						}
						else {
							Display::setConsoleCursorCoordinate(144, 31);
							cout << "你拒絕購買【" << sites[currentLocation].name << "】";
						}
					}
				}
				else {//有主地
					//若達成地產升級條件，詢問是否升級(自己地)
					if (sites[currentLocation].owner == playerIter->playerID && sites[currentLocation].estateLevel < 3) {
						//如果回答yes(尚未實作)
						playerIter->UpgradeAnEstate(currentLocation, sites);
					}
					//若踩到其他玩家之地產，進行付費(他人地)
					else if (sites[currentLocation].owner != playerIter->playerID) {
						playerIter->PayForTheToll(currentLocation, sites, players);
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

		Display::setConsoleCursorCoordinate(144, 40);
		cout << "請按任意鍵繼續．．．";
		while (commandPress = _getch()) {
			if (commandPress == KEYBOARD_ESCAPE) {
				this->openOptions();
			}
			else {
				break;
			}
		}

		//playerIter->money -= 100000;

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
		if (playerNum == 1 || this->remainTurn == 1) {
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

		// 尋找下個玩家
		this->whosTurn++;
		if (this->whosTurn % this->players.size() == 0) {
			this->remainTurn--;
			this->whosTurn %= this->players.size();
		}
		playerIter = players.begin() + this->whosTurn;
		


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
		string temp;
		inputFile >> temp;
		inputFile >> whosTurn;
		for (int i = 0; i < allPlayers; i++) {
			stringstream ss;
			int index, location, money;
			int ownEstate;
			int level;
			inputFile >> index;
			inputFile >> location;
			inputFile >> money;
			players.push_back(Player(index, location, money, 0, 0, 0));
			getline(inputFile, temp);
			//inputFile >> temp;
			ss << temp;
			int count = 0;
			while (ss >> ownEstate)
			{
				players[i].estate.push_back(sites[ownEstate]);
				sites[ownEstate].owner = i;
				ss >> level;
				players[i].estate[count].estateLevel = level;
				sites[ownEstate].estateLevel = level;
				count++;
				//if (ss.fail()) break;//確認stringstream有正常流出，沒有代表空了
			}
		}


		// 角色排序開始
		for (int i = 0; i < players.size() - 1; i++) {
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
	inputFile.close();
}

void Game::openOptions() {
	Display::showGameOptions();
	//this->gameLife = false;
	return;
}