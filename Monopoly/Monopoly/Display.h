#pragma once

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <time.h>
#include <Windows.h>
#include <iostream>

using namespace std;

class Display
{
public:
	Display();
	static void rollDiceAnimate(int a);
	static void printBoard();
	static void printCurrentPlayer(int a);
	static void printRound(int a);
	static void printRightSpace();
	static void printMainMenu();
	static void setConsoleCursorCoordinate(int = 0, int = 0);
	static void cursorVisiable(bool);
	static void showGameOptions();
private:
	static void printDice(int num);
	static string dice[6][3];
	static string bigNumber[10][5];
	static string board[49];
	static string rightSpace[49];
	static string start[9];
	static string chance[9];
	static string opportunity[9];
	static CONSOLE_CURSOR_INFO cci;
};

#endif // !_DISPLAY_H_
