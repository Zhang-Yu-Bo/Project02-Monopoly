#pragma once
#include "Display.h"
#include "Site.h"
#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <fstream>

#define KEYBOARD_UP 72
#define KEYBOARD_DOWN 80
#define KEYBOARD_LEFT 75
#define KEYBOARD_RIGHT 77
#define KEYBOARD_ENTER 13
#define KEYBOARD_ESCAPE 27

using namespace std;

#ifndef _GAME_H_
#define _GAME_H_

class Game
{
public:
	// 地圖檔名
	Game(string);
	void start();
	bool isGameAlive();
	void process();
private:
	// ...內部函式
	void loadMap();
	// ...變數
	string mapFileName;
	bool life;
	vector<Site> sites;
	vector<Player> players;
	int playerState;
};

#endif // !_GAME_H_

