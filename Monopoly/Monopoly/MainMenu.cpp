#include "MainMenu.h"

MainMenu::MainMenu() {
	Display::cursorVisiable(false);
}

int MainMenu::showMenu() {
	// 調整視窗大小
	system("mode con cols=50 lines=10");
	// 繪製Menu
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
				return 1;
			}
			else if (y == 1) {
				// 讀取地圖
				system("cls");
				Display::setConsoleCursorCoordinate(0, 0);
				cout << "請輸入地圖檔名（無須打副檔名、輸入exit返回）：\n";
				Display::setConsoleCursorCoordinate(0, 1);
				return 2;
			}
			else if (y == 2) {
				// 結束遊戲
				return 0;
			}
		}

		cout << "\b\b　";
		y = (y > 2) ? 0 : y;
		y = (y < 0) ? 2 : y;
		Display::setConsoleCursorCoordinate(x, y);
		cout << "→";

	}
}