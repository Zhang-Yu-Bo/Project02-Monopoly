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
	//行為
	//玩家移動call player裡的function
	//踩到格子的行為
		//有主地OR無主地OR功能格(機會、命運)
		//無:是否購買(詢問)
			//是:call player裡的function
		//有:誰的
			//別人的:付錢
			//自己的:是否升級(或已最高等不能升級)(詢問)call player裡的function
		//功能格:做事
private:
	// ...內部函式
	void loadMap();
	void openOptions();
	// ...變數
	string mapName; //地圖名稱，與mapFileName不同
	int allPlayers; //總共多少玩家
	string mapFileName;
	bool gameLife;
	vector<Site> sites;
	vector<Player> players;
	// 誰的回合
	int whosTurn;
	// 剩餘回合
	int remainTurn;

};

#endif // !_GAME_H_

