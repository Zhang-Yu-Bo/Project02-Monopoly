#pragma once
#include "Site.h"
#include <vector>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
public:
	// 玩家編號、所在位置、擁有金錢
	Player(int, int, int);

	int playerID;
	int location;
	int money;
	vector<Site> estate;
private:
	
};

#endif // !_PLAYER_H_

