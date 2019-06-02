#include "MainMenu.h"

MainMenu::MainMenu() {
	Display::cursorVisiable(false);
}

int MainMenu::showMenu() {
	// �վ�����j�p
	system("mode con cols=50 lines=10");
	// ø�sMenu
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
				// �}�l�s��
				return 1;
			}
			else if (y == 1) {
				// Ū���a��
				system("cls");
				Display::setConsoleCursorCoordinate(0, 0);
				cout << "�п�J�a���ɦW�]�L�������ɦW�B��Jexit��^�^�G\n";
				Display::setConsoleCursorCoordinate(0, 1);
				return 2;
			}
			else if (y == 2) {
				// �����C��
				return 0;
			}
		}

		cout << "\b\b�@";
		y = (y > 2) ? 0 : y;
		y = (y < 0) ? 2 : y;
		Display::setConsoleCursorCoordinate(x, y);
		cout << "��";

	}
}