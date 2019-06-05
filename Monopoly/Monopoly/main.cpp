#include "MainMenu.h"
#include "Game.h"
#include "Stock.h"
#include <iostream>
#include <string>

using namespace std;

string Stock::companyA = "NTUST���q";
string Stock::companyB = "NTU���q";
int Stock::companyA_money = 100;
int Stock::companyB_money = 100;
int Stock::companyA_remainNum = 100;
int Stock::companyB_remainNum = 100;

int main(void) {
	MainMenu menu;
	int nextStep = 0;
	srand((unsigned)time(NULL));//set "random" seed	
	(int)((rand() / (RAND_MAX + 1.0)) * (6 - 1 + 1.0) + 1);//�o���Ĥ@�өT�w�Ʀr
	while (nextStep = menu.showMenu()) {
		string fileName = "basemap";
		if (nextStep == 2) {
			// ...Ū���a��
			cin >> fileName;
		}
		if (fileName != "exit") {
			// �}�l�C��
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