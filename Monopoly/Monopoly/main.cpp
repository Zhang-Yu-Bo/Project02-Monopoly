#include "MainMenu.h"
#include "Game.h"
#include "Stock.h"
#include <iostream>
#include <string>

using namespace std;

string Stock::companyA = "NTUST公司";
string Stock::companyB = "NTU公司";
int Stock::companyA_money = 100;
int Stock::companyB_money = 100;
int Stock::companyA_remainNum = 100;
int Stock::companyB_remainNum = 100;

int main(void) {
	MainMenu menu;
	int nextStep = 0;
	srand((unsigned)time(NULL));//set "random" seed	
	(int)((rand() / (RAND_MAX + 1.0)) * (6 - 1 + 1.0) + 1);//濾掉第一個固定數字
	while (nextStep = menu.showMenu()) {
		string fileName = "basemap";
		if (nextStep == 2) {
			// ...讀取地圖
			cin >> fileName;
		}
		if (fileName != "exit") {
			// 開始遊戲
			Stock::initial();
			Game newGame(fileName);
			newGame.start();
			while (newGame.isGameAlive()) {
				newGame.process();
			}
			newGame.~Game();
		}
	}
	return 0;
}