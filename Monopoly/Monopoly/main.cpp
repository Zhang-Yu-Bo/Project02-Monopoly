#include "MainMenu.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	MainMenu menu;
	int nextStep = 0;
	srand((unsigned)time(NULL));//set "random" seed	
	(int)((rand() / (RAND_MAX + 1.0)) * (6 - 1 + 1.0) + 1);//�o���Ĥ@�өT�w�Ʀr
	while (nextStep = menu.showMenu()) {
		string fileName = "basemap";
		if (nextStep == 2) {
			// ...Ū���a��
			getline(cin, fileName);
		}
		if (fileName != "exit") {
			// �}�l�C��
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