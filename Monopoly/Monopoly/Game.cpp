#include "Game.h"

Game::Game(string fileName = "basemap") {

	system("cls");
	Display::setConsoleCursorCoordinate(0, 0);

	// initial condition
	this->mapFileName = fileName;
	this->gameLife = true;
	this->whosTurn = 0;
	this->allPlayers = 0;
	this->mapName = "";
	this->remainTurn = 0;

	// loading Map from file
	this->loadMap();
}

Game::~Game() {
	this->allPlayers = 0;
	this->mapName = "";
	this->mapFileName = "";
	this->gameLife = false;
	this->whosTurn = 0;
	this->remainTurn = 0;
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
	//Display::yesNoDialog("警告", "你這臭肥宅", "因油到不行", "罰3000元");
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

		/// 確認玩家數量&剩餘回合
		playerNum = 0;
		for (int i = 0; i < players.size(); i++) {
			if (players[i].money >= 0) {
				playerNum++;
			}
		}
		/// 勝負判定開始
		if (playerNum == 1 || this->remainTurn <= 0) {
			Display::setColor(7, 0);
			system("cls");
			system("mode con cols=50 lines=10");
			Player winner(0, 0, 0, 0, 0, 0);
			int max = 0;
			for (int i = 0; i < players.size(); i++) {
				if (players[i].money > max) {
					winner = players[i];
					max = players[i].money;
				}
			}
			cout << "Player" << (winner.playerID+1) << " is winner.\n";
			this->gameLife = false;
			system("pause");
			return;
		}
		/// 勝負判定結束

		/// 全畫面更新
		Display::setColor();
		system("cls");
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
		Display::clearPlayLog();

		// 玩家行為開始
		bool isUsingControlDice = false;

		if (!playerIter->cannotMove) {//可移動(回合沒被跳過)

			if (playerIter->barrier>0 || playerIter->controlledDice>0) {//擁有道具的情況
				//詢問並顯示是否使用道具
				//路障:剩餘數量N
				Display::setConsoleCursorCoordinate(144, 26);
				if (playerIter->barrier > 0 && sites[playerIter->location].barrier == false) {
					cout << "道具【路障】尚餘";
					cout << std::right << setw(2) << setfill('0') << playerIter->barrier;
					cout << "個，請問要使用嗎?(y/n)：";
					string temp = "";
					cin >> temp;
					Display::setConsoleCursorCoordinate(144, 27);
					if (temp == "y" || temp == "Y") {
						playerIter->PlaceABarrier(playerIter->location, sites);
						cout << "你在【" << sites[playerIter->location].name << "】放置了路障，你這臭GG";
					}
					else {
						cout << "你選擇不設置路障，你是個好人";
					}
					Display::setConsoleCursorCoordinate(144, 28);
					cout << "道具【路障】尚餘";
					cout << std::right << setw(2) << setfill('0') << playerIter->barrier;
					cout << "個";
					/// 等待輸入開始
					Display::setConsoleCursorCoordinate(144, 29);
					cout << "請按任意鍵繼續遊戲．．．";
					while (commandPress = _getch()) {
						if (commandPress == KEYBOARD_ESCAPE) {
							int temp = this->openOptions();
							if (temp == 2) {
								return;
							}
							Display::setConsoleCursorCoordinate(144, 29);
							cout << "請按任意鍵繼續遊戲．．．";
						}
						else {
							break;
						}
					}
					/// 等待輸入結束
				}
				Display::clearPlayLog();
				//遙控骰子:剩餘數量N
				//請輸入欲擲出點數
				Display::setConsoleCursorCoordinate(144, 26);
				if (playerIter->controlledDice > 0) {
					cout << "道具【遙控骰子】尚餘";
					cout << std::right << setw(2) << setfill('0') << playerIter->controlledDice;
					cout << "個，請問要使用嗎?(y/n)：";
					string temp = "";
					cin >> temp;
					Display::setConsoleCursorCoordinate(144, 27);
					if (temp == "y" || temp == "Y") {
						isUsingControlDice = true;
						playerIter->controlledDice--;
					}
					else {
						cout << "你選擇不使用遙控骰子";
					}
					Display::setConsoleCursorCoordinate(144, 28);
					cout << "道具【遙控骰子】尚餘";
					cout << std::right << setw(2) << setfill('0') << playerIter->controlledDice;
					cout << "個";
					/// 等待輸入開始
					Display::setConsoleCursorCoordinate(144, 29);
					cout << "請按任意鍵繼續遊戲．．．";
					while (commandPress = _getch()) {
						if (commandPress == KEYBOARD_ESCAPE) {
							int temp = this->openOptions();
							if (temp == 2) {
								return;
							}
							Display::setConsoleCursorCoordinate(144, 29);
							cout << "請按任意鍵繼續遊戲．．．";
						}
						else {
							break;
						}
					}
					/// 等待輸入結束
				}
				Display::clearPlayLog();
			}


			int point = playerIter->RollADice();
			if (!isUsingControlDice) {
				/// 等待輸入開始
				Display::setConsoleCursorCoordinate(144, 26);
				cout << "請按任意鍵骰動骰子．．．";
				while (commandPress = _getch()) {
					if (commandPress == KEYBOARD_ESCAPE) {
						int temp = this->openOptions();
						if (temp == 2) {
							return;
						}
						Display::setConsoleCursorCoordinate(144, 26);
						cout << "請按任意鍵骰動骰子．．．";
					}
					else {
						break;
					}
				}
				/// 等待輸入結束
			}
			else {
				Display::setConsoleCursorCoordinate(144, 26);
				cout << "由於使用了遙控骰子，請輸入數字(1～6)：";
				cin >> point;
				point = (point > 6) ? (point % 6 + 1) : point;
			}

			Display::rollDiceAnimate(point);									// 顯示骰子動畫
			Display::clearPlayLog();											// 清除PlayLog
			cout << "現在骰到了 " << point;
			Display::setConsoleCursorCoordinate(144, 27);
			cout << "玩家 " << playerIter->playerID + 1 << "從【" << sites[playerIter->location].name << "】";

			bool isCrossingWall = playerIter->Move(point, sites);					// 移動玩家
			int currentLocation = playerIter->location;

			if (isCrossingWall == false) {
				// 撞牆了(障礙物)
				Display::setConsoleCursorCoordinate(144, 28);
				cout << "撞到了該死的障礙物，因此";
			}

			Display::setConsoleCursorCoordinate(144, 29);
			cout << "移動到";

			Display::setConsoleCursorCoordinate(150, 29);
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
						string temp;
						cin >> temp;
						if (temp == "y" || temp == "Y") {
							playerIter->ProchaseAnEstate(currentLocation, sites);

							for (int i = 0; i < 28; i++) {
								if (sites[i].owner != -1)
									Display::printOwnEstate(sites[i], players);
							}

							Display::setConsoleCursorCoordinate(144, 31);
							cout << "你成為了【" << sites[currentLocation].name << "】的Master，恭喜你";
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
						
						Display::setConsoleCursorCoordinate(144, 30);
						cout << "你是【" << sites[currentLocation].name << "】的Master，想讓它（她）升級嗎?(y/n)：";
						string temp;
						cin >> temp;
						if (temp == "y" || temp == "Y") {
							playerIter->UpgradeAnEstate(currentLocation, sites);

							for (int i = 0; i < 28; i++) {
								if (sites[i].owner != -1)
									Display::printOwnEstate(sites[i], players);
							}

							Display::setConsoleCursorCoordinate(144, 31);
							cout << "恭喜你讓【" << sites[currentLocation].name << "】更加臣服於你";
						}
						else {
							Display::setConsoleCursorCoordinate(144, 31);
							cout << "你拒絕讓【" << sites[currentLocation].name << "】升級";
						}
						
					}
					//若踩到其他玩家之地產，進行付費(他人地)
					else if (sites[currentLocation].owner != playerIter->playerID) {

						Display::setConsoleCursorCoordinate(144, 30);
						cout << "【" << sites[currentLocation].name << "】是玩家 "<< sites[currentLocation].owner+1 <<"的土(老)地(婆)，必須繳交過路費";
						Display::setConsoleCursorCoordinate(144, 31);
						cout << "你的金額從＄" << setw(6) << setfill(' ') << playerIter->money << "→＄";
						playerIter->PayForTheToll(currentLocation, sites, players);
						Display::setConsoleCursorCoordinate(166, 31);
						cout << setw(6) << setfill(' ') << playerIter->money;

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

		/// 等待輸入開始
		Display::setConsoleCursorCoordinate(144, 40);
		cout << "請按任意鍵繼續．．．";
		while (commandPress = _getch()) {
			if (commandPress == KEYBOARD_ESCAPE) {
				int temp = this->openOptions();
				if (temp == 2) {
					return;
				}
				Display::setConsoleCursorCoordinate(144, 40);
				cout << "請按任意鍵繼續．．．";
			}
			else {
				break;
			}
		}
		/// 等待輸入結束

		// 破產測試
		//if (playerIter->playerID==0&&playerIter->money>0)
		//	playerIter->money -= 100000;

		/// 破產判定開始
		for (int i = 0; i < players.size(); i++) {
			if (players[i].money < 0) {
				// 刪除地點的擁有者
				for (int j = 0; j < players[i].estate.size(); j++) {
					sites[players[i].estate[j].location].estateLevel = 0;
					sites[players[i].estate[j].location].owner = -1;
				}
				// 刪除破產者的擁有地
				players[i].estate.erase(players[i].estate.begin(), players[i].estate.end());
			}
		}
		/// 破產判定結束

		/// 尋找下個玩家開始
		do {
			this->whosTurn++;
			if (this->whosTurn % this->players.size() == 0) {
				this->remainTurn--;
				this->whosTurn %= this->players.size();
			}
			playerIter = players.begin() + this->whosTurn;
		} while (playerIter->money < 0);
		/// 尋找下個玩家結束
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


		/// 角色排序開始
		for (int i = 0; i < players.size() - 1; i++) {
			for (int j = 0; j < players.size() - 1; j++) {
				if (players[j].playerID > players[j + 1].playerID) {
					Player temp = players[j];
					players[j] = players[j + 1];
					players[j + 1] = temp;
				}
			}
		}
		/// 角色排序結束

	}
	inputFile.close();
}

int Game::openOptions() {
	Display::showGameOptions();
	Display::setConsoleCursorCoordinate(14, 32);
	Display::setColor(150);
	cout << "★";
	int commandPress = 0, y = 32;
	while (commandPress = _getch()) {
		if (commandPress == KEYBOARD_DOWN) {
			Display::setConsoleCursorCoordinate(14, y);
			Display::setColor(240);
			cout << "　";
			y += 4;
		}
		else if (commandPress == KEYBOARD_UP) {
			Display::setConsoleCursorCoordinate(14, y);
			Display::setColor(240);
			cout << "　";
			y -= 4;
		}
		else if (commandPress == KEYBOARD_ENTER) {
			if (y == 32) {
				/// 繼續遊戲
				Display::setColor();
				system("cls");
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
				return 0;
			}
			else if (y == 36) {
				/// 儲存遊戲
				// 清除畫面
				Display::setColor(7, 0);
				system("cls");
				system("mode con cols=50 lines=10");
				Display::setConsoleCursorCoordinate(0, 0);
				cout << "請輸入欲儲存檔名(輸入exit返回)：\n";
				string saveFileName = "";
				cin >> saveFileName;

				if (saveFileName != "exit") {
					fstream output("Map/" + saveFileName + ".txt",ios::out);
					if (output.is_open()) {
						int playerNum = 0;
						for (int i = 0; i < players.size(); i++) {
							if (players[i].money >= 0) {
								playerNum++;
							}
						}
						output << saveFileName << " " << this->remainTurn << " " << playerNum << endl;

						for (int i = 0; i < sites.size(); i++) {
							output << setw(2) << setfill('0') << i << " " << sites[i].name << " " << sites[i].type;
							if (sites[i].type == 1) {
								output << " " << sites[i].firstPrice
									<< " " << sites[i].initialToll
									<< " " << sites[i].firstStageToll
									<< " " << sites[i].secondStageToll
									<< " " << sites[i].thirdStageToll;
							}
							output << endl;
						}
						output << "playerstate " << this->whosTurn << endl;
						for (int i = 0; i < this->players.size(); i++) {
							output << this->players[i].playerID
								<< " " << setw(2) << setfill('0') << this->players[i].location;
							output << " " << this->players[i].money;
							for (int j = 0; j < this->players[i].estate.size(); j++) {
								output << " " << setw(2) << setfill('0') << this->players[i].estate[j].location;
								output << " " << this->players[i].estate[j].estateLevel;
							}
							output << endl;
						}

						output.close();
					}
				}
				
				Display::setColor();
				system("cls");
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

				return 1;
			}
			else if (y==40) {
				/// 結束遊戲
				this->gameLife = false;
				Display::setColor(7, 0);
				return 2;
			}
		}
		else if (commandPress == KEYBOARD_ESCAPE) {
			Display::setColor();
			system("cls");
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
			return 0;
		}
		y = (y < 32) ? 40 : y;
		y = (y > 40) ? 32 : y;
		Display::setConsoleCursorCoordinate(14, y);
		Display::setConsoleCursorCoordinate(14, y);
		Display::setColor(150);
		cout << "★";

	}
	return 0;
}