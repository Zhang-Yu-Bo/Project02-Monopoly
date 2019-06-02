#include "MainMenu.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	MainMenu menu;
	int nextStep = 0;
	srand((unsigned)time(NULL));//set "random" seed	
	(int)((rand() / (RAND_MAX + 1.0)) * (6 - 1 + 1.0) + 1);//濾掉第一個固定數字
	while (nextStep = menu.showMenu()) {
		string fileName = "basemap";
		if (nextStep == 2) {
			// ...讀取地圖
			getline(cin, fileName);
		}
		if (fileName != "exit") {
			// 開始遊戲
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