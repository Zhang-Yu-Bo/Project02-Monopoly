#include "MainMenu.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	MainMenu menu;
	int nextStep = 0;
	while (nextStep = menu.showMenu()) {
		string fileName = "basemap";
		if (nextStep == 2) {
			// ...Åª¨ú¦a¹Ï
			getline(cin, fileName);
		}
		if (fileName != "exit") {
			Game newGame(fileName);
			newGame.start();
			while (newGame.isGameAlive()) {
				newGame.process();
			}
		}
	}
	return 0;
}