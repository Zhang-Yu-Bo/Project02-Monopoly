#include "Display.h"
#include "Game.h"

string Display::dice[6][3] = {
		{"　　　"
		,"　●　"
		,"　　　"} ,
		{"　　●"
		,"　　　"
		,"●　　"} ,
		{"　　●"
		,"　●　"
		,"●　　"} ,
		{"●　●"
		,"　　　"
		,"●　●"} ,
		{"●　●"
		,"　●　"
		,"●　●"} ,
		{"●　●"
		,"●　●"
		,"●　●"}
};
string Display::bigNumber[10][5] = {
		{"■■■"
		,"■　■"
		,"■　■"
		,"■　■"
		,"■■■"} ,
		{"　　■"
		,"　　■"
		,"　　■"
		,"　　■"
		,"　　■"} ,
		{"■■■"
		,"　　■"
		,"■■■"
		,"■　　"
		,"■■■"} ,
		{"■■■"
		,"　　■"
		,"■■■"
		,"　　■"
		,"■■■"} ,
		{"■　■"
		,"■　■"
		,"■■■"
		,"　　■"
		,"　　■"} ,
		{"■■■"
		,"■　　"
		,"■■■"
		,"　　■"
		,"■■■"} ,
		{"■■■"
		,"■　　"
		,"■■■"
		,"■　■"
		,"■■■"} ,
		{"■■■"
		,"　　■"
		,"　　■"
		,"　　■"
		,"　　■"} ,
		{"■■■"
		,"■　■"
		,"■■■"
		,"■　■"
		,"■■■"} ,
		{"■■■"
		,"■　■"
		,"■■■"
		,"　　■"
		,"　　■"}
};
string Display::board[49] = {
		{"．－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－．"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－｜－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　／＼　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　／　　＼　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　／　　　　＼　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　／　　　機　　＼　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－｜　　　　　　／　　　　　　　／　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜－－－－－－｜"},
		{"｜　　　　　　｜　　　　　／　　　！　　　／　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－｜　　　　／　　　　　　　／　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜－－－－－－｜"},
		{"｜　　　　　　｜　　　　＼　　會　　　／　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　＼　　　　／　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　＼　　／　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　＼／　　　　　　　　　　　　　　．－－－－－．　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－｜　　　　　　　　　　　　　　　　　　　　　　　｜　●　●　｜　　　　　　　　　　　　　　　　　　　　　　　　　｜－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　｜　　●　　｜　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－｜　　　　　　　　　　　　　　　　　　　　　　　｜　●　●　｜　　　　　　　　　　　　　　　　／＼　　　　　　　｜－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　｜　　　　　　　　　　　　　　　／　　＼　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　．－－－－－．　　　　　　　　　　　　　　／　　　　＼　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　／　　　命　　＼　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　／　　　　　　　／　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　／　　　？　　　／　　　　　｜　　　　　　｜"},
		{"｜－－－－－－｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　／　　　　　　　／　　　　　　｜－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＼　　運　　　／　　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＼　　　　／　　　　　　　　｜－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＼　　／　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＼／　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜　　　　　　｜"},
		{"．－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－．"}
};
string Display::rightSpace[49] = {
		{"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－．"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"　●　１　　　　　　　　　　　　　　｜　●　２　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"　＄　　　　　　　　　　　　　　　　｜　＄　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"　●　３　　　　　　　　　　　　　　｜　●　４　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"　＄　　　　　　　　　　　　　　　　｜　＄　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　｜"},
		{"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－｜"},
		{"　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　目前玩家：　　　　　　　　｜　當前回合：　　■■■　　■■■　　　　　｜"},
		{"　　　　　　　　　　　　　　｜　　　　　　　　■　■　　■　■　　　　　｜"},
		{"　　　　　　　　　　　　　　｜　　　　　　　　■■■　　■■■　　　　　｜"},
		{"　　　　　　　　　　　　　　｜　　　　　　　　■　■　　■　■　　　　　｜"},
		{"　　　　　　　　　　　　　　｜　　　　　　　　■■■　　■■■　　　　　｜"},
		{"　　　　　　　　　　　　　　｜　　　　　　　　　　　　　　　　　　　　　｜"},
		{"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜"},
		{"－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－．"}
};
string Display::start[9] = {
		{"．－－－－－－．"},
		{"｜　　　　　　｜"},
		{"｜　起點　　　｜"},
		{"｜ＳＴＡＲＴ　｜"},
		{"｜　　　　　　｜"},
		{"｜↓　　ＧＯ！｜"},
		{"｜　　　　　　｜"},
		{"｜　　　　　　｜"},
		{"．－－－－－－．"},
};
string Display::chance[9] = {
		{"．－－－－－－．"},
		{"｜　　　　　　｜"},
		{"｜　機會　　　｜"},
		{"｜ＣＨＡＮＣＥ｜"},
		{"｜　　　　　　｜"},
		{"｜　　！！！　｜"},
		{"｜　　　　　　｜"},
		{"｜　　　　　　｜"},
		{"．－－－－－－．"},
};
string Display::opportunity[9] = {
		{"．－－－－－－．"},
		{"｜　　　　　　｜"},
		{"｜　命運　　　｜"},
		{"｜ＯＰＰＯＲ－｜"},
		{"｜ＴＵＮＩＴＹ｜"},
		{"｜　　　　　　｜"},
		{"｜　　？？？　｜"},
		{"｜　　　　　　｜"},
		{"．－－－－－－．"},
};
string Display::option[17] = {
	{"■■■■■■■■■■■■"},
	{"■　　　　　　　　　　■"},
	{"■　■　■　■　■　■■"},
	{"■　　　　　　　　　　■"},
	{"■　　　繼續遊戲　　　■"},
	{"■　　　　　　　　　　■"},
	{"■　■■■■■■■■　■"},
	{"■　　　　　　　　　　■"},
	{"■　　　儲存遊戲　　　■"},
	{"■　　　　　　　　　　■"},
	{"■　■■■■■■■■　■"},
	{"■　　　　　　　　　　■"},
	{"■　　　離開遊戲　　　■"},
	{"■　　　　　　　　　　■"},
	{"■■　■　■　■　■　■"},
	{"■　　　　　　　　　　■"},
	{"■■■■■■■■■■■■"}
};

CONSOLE_CURSOR_INFO Display::cci;

Display::Display() {
	srand(time(NULL));
}

void Display::SetColor(int f = 7, int b = 0)
{
	unsigned short ForeColor = f + 16 * b;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor);
}



void Display::rollDiceAnimate(int a)
{
	a--;
	for (int i = 0; i < 20; i++)
	{
		printDice(rand() % 6);
		Sleep(100);
	}
	printDice(a);
}

void Display::printBoard()
{
	setConsoleCursorCoordinate(0, 0);
	for (int i = 0; i < 49; i++)
	{
		cout << board[i];
		setConsoleCursorCoordinate(0, i + 1);
	}
	//使整體畫面上提，不清楚自己註解掉下行跑一次看看就知道了
	setConsoleCursorCoordinate(0, 0);
}

void Display::printEstate(const vector<Site>& sites)
{
	for (int i = 0; i < 10; i++) {
		setConsoleCursorCoordinate(0 + 14 * i, 0);
		switch (sites[i].type) {
		case 0:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(0 + 14 * i, j);
				cout << start[j] << endl;
			}
			break;
		case 1:
			setConsoleCursorCoordinate(2 + 14 * i, 3);
			cout << sites[i].name;
			setConsoleCursorCoordinate(2 + 14 * i, 5);
			cout << "$ " << sites[i].firstPrice;
			break;
		case -1:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(0 + 14 * i, j);
				cout << opportunity[j] << endl;
			}
			break;
		case -2:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(0 + 14 * i, j);
				cout << chance[j] << endl;
			}
			break;
		}
	}
	for (int i = 10; i < 15; i++) {
		setConsoleCursorCoordinate(126, 8 + (i-10) );
		switch (sites[i].type) {
		case 0:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(126, 8 + (i-10) + j);
				cout << start[j] << endl;
			}
			break;
		case 1:
			setConsoleCursorCoordinate(2 + 126, 11 + 8 * (i - 10));
			cout << sites[i].name;
			setConsoleCursorCoordinate(2 + 126, 13 + 8 * (i - 10));
			cout << "$ " << sites[i].firstPrice;
			break;
		case -1:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(126, 8 + (i-10) + j);
				cout << opportunity[j] << endl;
			}
			break;
		case -2:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(126, 8 + (i-10) + j);
				cout << chance[j] << endl;
			}
			break;
		}
	}
	for (int i = 15; i < 24; i++) {
		setConsoleCursorCoordinate(112 - 14 * (i - 15), 40);
		switch (sites[i].type) {
		case 0:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(112 - 14 * (i - 15), 40 + j);
				cout << start[j] << endl;
			}
			break;
		case 1:
			setConsoleCursorCoordinate(2 + 112 - 14 * (i - 15), 43);
			cout << sites[i].name;
			setConsoleCursorCoordinate(2 + 112 - 14 * (i - 15), 45);
			cout << "$ " << sites[i].firstPrice;
			break;
		case -1:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(112 - 14 * (i - 15), 40 + j);
				cout << opportunity[j] << endl;
			}
			break;
		case -2:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(112 - 14 * (i - 15), 40 + j);
				cout << chance[j] << endl;
			}
			break;
		}
	}
	for (int i = 24; i < 28; i++) {
		setConsoleCursorCoordinate(0, 32 - 8 * (i-24));
		switch (sites[i].type) {
		case 0:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(0, 32 - 8 * (i-24) + j);
				cout << start[j] << endl;
			}
			break;
		case 1:
			setConsoleCursorCoordinate(2, 35 - 8 * (i-24));
			cout << sites[i].name;
			setConsoleCursorCoordinate(2, 37 - 8 * (i-24));
			cout << "$ " << sites[i].firstPrice;
			break;
		case -1:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(0, 32 - 8 * (i-24) + j);
				cout << opportunity[j] << endl;
			}
			break;
		case -2:
			for (int j = 0; j < 9; j++) {
				setConsoleCursorCoordinate(0, 32 - 8 * (i-24) + j);
				cout << chance[j] << endl;
			}
			break;
		}
	}
}

void Display::printCurrentPlayer(int a)
{
	setConsoleCursorCoordinate(158, 18);
	for (int i = 0; i < 5; i++) {
		cout << bigNumber[a][i];
		setConsoleCursorCoordinate(158, i + 19);
	}
	setConsoleCursorCoordinate(0, 0);
}

void Display::printPlayersstatus(const vector<Player> &players)
{
	int coordinate[4][2] = { {148,5},{186,5},{148,13},{186,13} };
	for (int i = 0; i < players.size(); i++) {
		setConsoleCursorCoordinate(coordinate[i][0],coordinate[i][1]);
		cout << setw(10) << left << players[i].money  << endl;
	}
}

void Display::printRound(int a)
{
	int x = a / 10;
	int y = a % 10;
	setConsoleCursorCoordinate(188, 18);
	for (int i = 0; i < 5; i++) {
		cout << bigNumber[x][i];
		setConsoleCursorCoordinate(188, i + 19);
	}
	setConsoleCursorCoordinate(198, 18);
	for (int i = 0; i < 5; i++) {
		cout << bigNumber[y][i];
		setConsoleCursorCoordinate(198, i + 19);
	}
	setConsoleCursorCoordinate(0, 0);
}

void Display::printRightSpace()
{
	setConsoleCursorCoordinate(142, 0);
	for (int i = 0; i < 49; i++)
	{
		cout << rightSpace[i];
		setConsoleCursorCoordinate(142, i + 1);
	}
	//使整體畫面上提，不清楚自己註解掉下行跑一次看看就知道了
	setConsoleCursorCoordinate(0, 0);
}

void Display::setConsoleCursorCoordinate(int x, int y)
{
	COORD cursorPosition;
	cursorPosition.X = x;	cursorPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Display::printDice(int num)
{
	for (int i = 0; i < 3; i++) {
		setConsoleCursorCoordinate(66, 24 + i);
		cout << dice[num][i];
	}
}

void Display::printMainMenu() {
	setConsoleCursorCoordinate(0, 0);
	cout << "→開始新局";
	setConsoleCursorCoordinate(2, 1);
	cout << "讀取地圖";
	setConsoleCursorCoordinate(2, 2);
	cout << "結束遊戲";
}

void Display::printPlayerStep(const vector<Player>& players)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < players.size(); j++) {
			setConsoleCursorCoordinate(4 + 14 * i + 2 * j, 7);
			if (i == players[j].location) cout << j + 1 << endl;
			else cout << " " << endl;
		}
	}
	for (int i = 10; i < 15; i++) {
		for (int j = 0; j < players.size(); j++) {
			setConsoleCursorCoordinate(130 + 2 * j, 15 + (i - 10) * 8);
			if (i == players[j].location) cout << j + 1 << endl;
			else cout << " " << endl;
		}
	}
	for (int i = 15; i < 24; i++) {
		for (int j = 0; j < players.size(); j++) {
			setConsoleCursorCoordinate(116 - 14 * (i - 15) + 2 * j, 47);
			if (i == players[j].location) cout << j + 1 << endl;
			else cout << " " << endl;
		}
	}
	for (int i = 24; i < 28; i++) {
		for (int j = 0; j < players.size(); j++) {
			setConsoleCursorCoordinate(4 + 2 * j, 39 - 8 * (i - 24));
			if (i == players[j].location) cout << j + 1 << endl;
			else cout << " " << endl;
		}
	}
}

void Display::cursorVisiable(bool flag) {
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = flag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Display::showGameOptions() {
	SetColor(240);
	for (int i = 0; i < 17; i++) {
		setConsoleCursorCoordinate(8, 28 + i);
		cout << option[i] << endl;
	}
	SetColor(7);
}