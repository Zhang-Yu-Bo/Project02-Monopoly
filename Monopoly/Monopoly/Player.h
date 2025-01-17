#pragma once
#include "Site.h"
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player{
public:
	// 玩家編號，所在位置，擁有金錢
	Player(int, int, int, int, int, int);
	int playerID;	
	int location;
	int money;
	int deposit;
	int loan;
	//tolls number(其值為持有數量)
	int barrier;
	int controlledDice;
	int cannotMove;//代表不能移動多少回合，0代表可以移動
	vector<Site> estate;
	map<string, int> stockNum;
	//行為
	
	int RollADice();//骰骰子(回傳骰了多少) 
	bool Move(int, vector<Site>&);//玩家移動(傳入移動步數,site)
	void ProchaseAnEstate(const int, vector<Site>&);//玩家購買房產(傳入房產地點,game裡的vector<Sites>&並一併修改)
	void UpgradeAnEstate(const int, vector<Site>&);//玩家升級房產(傳入房產地點,game裡的vector<Sites>&並一併修改)
	void PayForTheToll(const int, const vector<Site>&, vector<Player>&);
	void PlaceABarrier(const int, vector<Site>&);
	string FCEvents(const int,vector<Player>&);//傳入機會OR命運、所有玩家資料
	///踩過起點是否給錢
		//路障(道具)放置
};

#endif // !_PLAYER_H_

