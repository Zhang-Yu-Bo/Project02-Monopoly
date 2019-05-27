#pragma once
#include "Site.h"
#include <vector>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player{
public:
	// 玩家編號，所在位置，擁有金錢
	Player(int, int, int);
	//儲存是否持有道具的變數
	int barrier;
	int playerID;
	int location;
	int money;
	int cannotMove;//代表不能移動多少回合，0代表可以移動
	vector<Site> estate;
	//行為
	//骰骰子(回傳骰了多少) int RollDice();
	
	//移動
	///踩過起點是否給錢
		//有關詢問者(YN)
		//升級房產
		//房地產交易(estate)相關 bool BuyAHouse(vector<Site>);回傳是否購買成功
		//路障(道具)放置

private:
	
};

#endif // !_PLAYER_H_

