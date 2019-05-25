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
	static void printMainMenu();
	static void setConsoleCursorCoordinate(int x = 42, int y = 1);
private:
	static void printDice(int num);
	static string dice[6][3];
	static string board[49];
	static string start[9];
	static string chance[9];
	static string opportunity[9];
};

#endif // !_DISPLAY_H_
