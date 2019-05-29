#pragma once
#include "Site.h"
#include <cstdlib>
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
	
	int RollADice();//骰骰子(回傳骰了多少) 
	void Move(int);//玩家移動(傳入移動步數)
	void ProchaseAnEstate(int, vector<Site>&);//玩家購買房產(傳入房產地點,game裡的vector<Sites>&並一併修改)
	void UpgradeAnEstate(int, vector<Site>&);//玩家升級房產(傳入房產地點,game裡的vector<Sites>&並一併修改)
	///踩過起點是否給錢

		//有關詢問者(YN)
		//升級房產
		//房地產交易(estate)相關 bool BuyAHouse(vector<Site>);回傳是否購買成功
		//路障(道具)放置

	
};

#endif // !_PLAYER_H_

