#include "MainMenu.h"

MainMenu::MainMenu() {
	cout << "Monopoly\n";
}

void MainMenu::showMenu() {
	system("mode con cols=50 lines=10");
	//Display::printBoard();
	//Display::rollDiceAnimate(2);
	Display::printMainMenu();
	int command = 0;
	int x = 0, y = 0;
	Display::setConsoleCursorCoordinate(0, 0);
	while (command = _getch()) {
		if (command == KEYBOARD_UP) {
			y -= 1;
		}
		else if (command == KEYBOARD_DOWN) {
			y += 1;
		}
		else if (command == KEYBOARD_ENTER) {
			if (y == 0) {
				// 開始新局
			}
			else if (y == 1) {
				// 讀取地圖
			}
			else if (y == 2) {
				// 結束遊戲
				exit(1);
			}
		}

		cout << "\b\b　";
		y = (y > 2) ? 0 : y;
		y = (y < 0) ? 2 : y;
		Display::setConsoleCursorCoordinate(x, y);
		cout << "→";

	}
}