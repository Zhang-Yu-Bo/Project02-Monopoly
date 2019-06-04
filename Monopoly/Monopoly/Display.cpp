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
string Display::star[4] = {
	"　　　　　　",
	"　　 ★ 　　",
	"　　★★　　",
	"　 ★★★ 　"
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
		{"｜→　　ＧＯ！｜"},
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
string Display::number[4] = { "１","２" ,"３" ,"４" };

CONSOLE_CURSOR_INFO Display::cci;

Display::Display() {
	srand(time(NULL));
}

void SetColor(int f = 7, int b = 0)
{
	unsigned short ForeColor = f + 16 * b;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor);
}

void Display::setColor(const int f, const int b)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, f|b);
}

void Display::setColorForPlayer(const bool text, const int index)
{
	switch (index) {
	case 0 :
		if (text) setColor(FOREGROUND_RED);
		else setColor((FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED), BACKGROUND_RED);
		break;
	case 1:
		if (text) setColor(FOREGROUND_BLUE);
		else setColor((FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED), BACKGROUND_BLUE);
		break;
	case 2:
		if (text) setColor(FOREGROUND_GREEN);
		else setColor((FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED), BACKGROUND_GREEN);
		break;
	case 3:
		if (text) setColor((FOREGROUND_BLUE | FOREGROUND_GREEN));
		else setColor((FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED), (BACKGROUND_BLUE| BACKGROUND_GREEN));
		break;
	default:
		setColor();
		break;
	}
}



void Display::rollDiceAnimate(int a)
{
	a--;
	for (int i = 0; i < 20; i++)
	{
		printDice(rand() % 6);
		Sleep(50);
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

void Display::printPlayersStatus(const vector<Player> &players)
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

void Display::printRightSpace(int allplayers)
{
	int coordinate[4][2] = { {144,3},{182,3},{144,11},{182,11} };
	for (int i = 0; i < 49; i++)
	{
		setConsoleCursorCoordinate(142, i);
		cout << rightSpace[i];
	}
	for(int i = 0; i < allplayers; i++) {
		setColorForPlayer(1, i);
		setConsoleCursorCoordinate(coordinate[i][0], coordinate[i][1]);
		cout << "●　" << number[i];
	}
	setColorForPlayer();
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
	system("color 70");
	SetColor(112);
	setConsoleCursorCoordinate(0, 0);
	cout << "→　　　　　　　　開始新局　　";

	setConsoleCursorCoordinate(0, 1);
	cout << "　　　　　　　　　讀取地圖　　";
	setConsoleCursorCoordinate(0, 2);
	cout << "　　　　　　　　　結束遊戲　　";
	

	setConsoleCursorCoordinate(0, 5);
	blank("gray", 1);
	blank("purple", 1);
	blank("red", 22);
	blank("purple", 2);
	blank("red", 11);
	blank("purple", 2);
	blank("red", 11);
	blank("purple", 2);
	blank("red", 24);

	setConsoleCursorCoordinate(0, 6);
	blank("gray", 1);
	blank("purple", 1);
	blank("red", 12);
	blank("gray", 1);
	blank("purple", 1);
	blank("red", 4);
	blank("gray", 1);
	blank("red", 1);
	blank("purple", 1);
	blank("gray", 4);
	blank("purple", 1);
	blank("red", 1);
	blank("gray", 1);
	blank("red", 3);
	blank("gray", 2);
	blank("red", 1);
	blank("gray", 5);
	blank("red", 1);
	blank("gray", 4);
	blank("purple", 1);
	blank("red", 1);
	blank("gray", 5);
	blank("red", 1);
	blank("gray", 2);
	blank("red", 2);
	blank("gray", 2);
	blank("red", 1);
	blank("purple", 1);
	blank("gray", 1);
	blank("purple", 1);
	blank("red", 12);

	setConsoleCursorCoordinate(0, 7);
	blank("gray", 1);
	blank("purple", 1);
	blank("red", 12);
	blank("gray", 2);
	blank("red", 3);
	blank("gray", 2);
	blank("red", 1);
	blank("gray", 2);
	blank("gray", 2);
	blank("gray", 2);
	blank("gray", 4);
	blank("gray", 4);
	blank("gray", 4);
	blank("gray", 4);

	setConsoleCursorCoordinate(0, 8);
	for (int i = 0; i < 78; i++) {

	}
	setConsoleCursorCoordinate(0, 9);
	for (int i = 0; i < 78; i++) {

	}
	setConsoleCursorCoordinate(0, 10);
	for (int i = 0; i < 78; i++) {

	}
	setConsoleCursorCoordinate(0, 11);
	for (int i = 0; i < 78; i++) {

	}
	setConsoleCursorCoordinate(0, 12);
	for (int i = 0; i < 78; i++) {

	}
}

void Display::printPlayerStep(const vector<Player>& players)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < players.size(); j++) {
			setConsoleCursorCoordinate(4 + 14 * i + 2 * j, 7);
			setColorForPlayer(1, j);
			if (i == players[j].location) cout << number[j] << endl;
			else cout << " " << endl;
		}
	}
	for (int i = 10; i < 15; i++) {
		for (int j = 0; j < players.size(); j++) {
			setConsoleCursorCoordinate(130 + 2 * j, 15 + (i - 10) * 8);
			setColorForPlayer(1, j);
			if (i == players[j].location) cout << number[j] << endl;
			else cout << " " << endl;
		}
	}
	for (int i = 15; i < 24; i++) {
		for (int j = 0; j < players.size(); j++) {
			setConsoleCursorCoordinate(116 - 14 * (i - 15) + 2 * j, 47);
			setColorForPlayer(1, j);
			if (i == players[j].location) cout << number[j] << endl;
			else cout << " " << endl;
		}
	}
	for (int i = 24; i < 28; i++) {
		for (int j = 0; j < players.size(); j++) {
			setConsoleCursorCoordinate(4 + 2 * j, 39 - 8 * (i - 24));
			setColorForPlayer(1, j);
			if (i == players[j].location) cout << number[j] << endl;
			else cout << " " << endl;
		}
	}
	setColorForPlayer();
}

void Display::printOwnEstate(const Site& site, const vector<Player> & players)
{
	int x = 0, y = 0;
	if (site.location >= 0 && site.location < 10) {
		x = site.location;
		y = 0;
	}
	else if (site.location < 15) {
		x = 9;
		y = site.location - 9;
	}
	else if (site.location < 24) {
		x = 23 - site.location;
		y = 5;
	}
	else if (site.location < 28) {
		x = 0;
		y = (28 - site.location);
	}
	x *= 14;
	y *= 8;
	x += 2;
	y++;
	setConsoleCursorCoordinate(x, y);
	setColorForPlayer(false, players[site.owner].playerID);
	switch (site.estateLevel) {
	case 0:
		cout << star[0];
		break;
	case 1:
		cout << star[1];
		break;
	case 2:
		cout << star[2];
		break;
	case 3:
		cout << star[3];
		break;
	}
	setColorForPlayer();
}

void Display::printObstacle(const Site& site)
{
	int x = 0, y = 0;
	if (site.location >= 0 && site.location < 10) {
		x = site.location;
		y = 0;
	}
	else if (site.location < 15) {
		x = 9;
		y = site.location - 9;
	}
	else if (site.location < 24) {
		x = 23 - site.location;
		y = 5;
	}
	else if (site.location < 28) {
		x = 0;
		y = (28 - site.location);
	}
	x *= 14;
	y *= 8;
	x += 10;
	y += 4;
	setConsoleCursorCoordinate(x, y);
	SetColor(118);
	cout << "▲";
	setColor();
}

void Display::cursorVisiable(bool flag) {
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = flag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Display::dialog(string title, string line1 = "", string line2 = "", string line3 = "")
{
	setConsoleCursorCoordinate(80, 17);
	SetColor(79);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(80, 18);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(82, 18);
	cout << "　" << title;
	setConsoleCursorCoordinate(80, 19);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	//--------------------------------------
	setConsoleCursorCoordinate(80, 20);
	SetColor(143);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(80, 21);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(82, 21);
	cout << "　" << line1;
	setConsoleCursorCoordinate(80, 22);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(80, 23);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(82, 23);
	cout << "　" << line2;
	setConsoleCursorCoordinate(80, 24);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(80, 25);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(82, 25);
	cout << "　" << line3;
	setConsoleCursorCoordinate(80, 26);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setColor();
	//Sleep(10000);
}

void Display::yesNoDialog(string title, string line1 = "", string line2 = "", string line3 = "")
{
	setConsoleCursorCoordinate(80, 17);
	SetColor(79);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(80, 18);
	cout << "　" << title;
	for (int i = title.size() + 1; i < 24; i++) {
		cout << "　";
	}
	setConsoleCursorCoordinate(80, 19);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	//--------------------------------------
	setConsoleCursorCoordinate(80, 20);
	SetColor(143);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setConsoleCursorCoordinate(80, 21);
	cout << "　" << line1;
	for (int i = line1.size() + 1; i < 27; i++) {
		cout << "　";
	}
	setConsoleCursorCoordinate(80, 22);
	cout << "　　　　　　　　　　　　　　　　";
	SetColor(159);
	cout << "ＹＥＳ";
	SetColor(143);
	cout << "　　　";
	setConsoleCursorCoordinate(80, 23);
	cout << "　" << line2;
	for (int i = line2.size() + 1; i < 27; i++) {
		cout << "　";
	}
	setConsoleCursorCoordinate(80, 24);
	cout << "　　　　　　　　　　　　　　　　 ";
	SetColor(203);
	cout << "ＮＯ";
	SetColor(143);
	cout << " 　　　";
	setConsoleCursorCoordinate(80, 25);
	cout << "　" << line3;
	for (int i = line3.size() + 1; i < 26; i++) {
		cout << "　";
	}
	setConsoleCursorCoordinate(80, 26);
	cout << "　　　　　　　　　　　　　　　　　　　　　　";
	setColor();
	//Sleep(100000);
}

void Display::showGameOptions() {
	setColor(240);
	for (int i = 0; i < 17; i++) {
		setConsoleCursorCoordinate(8, 28 + i);
		cout << option[i] << endl;
	}
	setColor(7);
}

void Display::clearPlayLog() {
	for (int i = 0; i < 15; i++) {
		setConsoleCursorCoordinate(144, 26 + i);
		for (int j = 0; j < 34; j++) {
			// 34*2
			cout << "　";
		}
	}
	Display::setConsoleCursorCoordinate(144, 26);
}

void Display::blank(string type , int num)
{
	if (type == "red") SetColor(64);
	if (type == "gray") SetColor(112);
	if (type == "green") SetColor(96);
	if (type == "purple") SetColor(80);
	for (int i = 0; i < num; i++) {
		cout << "　";
	}
}
