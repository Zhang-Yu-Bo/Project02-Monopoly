#include "Display.h"

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
		{"｜↓　　　　　｜"},
		{"｜　　ＧＯ！　｜"},
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
		{"｜　機會　　　｜"},
		{"｜ＣＨＡＮＣＥ｜"},
		{"｜　　　　　　｜"},
		{"｜　　！！！　｜"},
		{"｜　　　　　　｜"},
		{"｜　　　　　　｜"},
		{"．－－－－－－．"},
};

CONSOLE_CURSOR_INFO Display::cci;

Display::Display() {
	srand(time(NULL));
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

void Display::printCurrentPlayer(int a)
{
	setConsoleCursorCoordinate(158, 18);
	for (int i = 0; i < 5; i++) {
		cout << bigNumber[a][i];
		setConsoleCursorCoordinate(158, i + 19);
	}
	setConsoleCursorCoordinate(0, 0);
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

void Display::cursorVisiable(bool flag) {
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = flag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Display::showGameOptions() {

}