#pragma once

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <time.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Player.h"
#include "Site.h"

using namespace std;

class Display
{
public:
	Display();
	static void setColor(const int = 0, const int = (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED));
	static void setColorForPlayer(const bool = true, const int = -1); //true 改字體顏色 false改背景顏色
	static void rollDiceAnimate(int a);
	static void printBoard();
	static void printEstate(const vector<Site>&);
	static void printCurrentPlayer(int a);
	static void printPlayersStatus(const vector<Player>&);
	static void printRound(int a);
	static void printRightSpace(int allplayers);
	static void printMainMenu();
	static void printPlayerStep(const vector<Player>&);
	static void printOwnEstate(const Site&, const vector<Player>&);
	static void printObstacle(const Site&);
	static void setConsoleCursorCoordinate(int = 0, int = 0);
	static void cursorVisiable(bool);
	static void dialog(string, string, string, string);
	static void yesNoDialog(string, string, string, string);
	static void showGameOptions();
	static void clearPlayLog();
private:
	static void printDice(int num);
	static string dice[6][3];
	static string bigNumber[10][5];
	static string board[49];
	static string rightSpace[49];
	static string start[9];
	static string chance[9];
	static string opportunity[9];
	static string option[17];
	static CONSOLE_CURSOR_INFO cci;
	static string number[4];
	static string star[4];
};

#endif // !_DISPLAY_H_
