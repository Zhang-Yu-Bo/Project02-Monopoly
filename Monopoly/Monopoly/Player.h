#pragma once
#include "Site.h"
#include <vector>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
public:
	// ���a�s���B�Ҧb��m�B�֦�����
	Player(int, int, int);

	int playerID;
	int location;
	int money;
	vector<Site> estate;
private:
	
};

#endif // !_PLAYER_H_

