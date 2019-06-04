#pragma once
#include <string>
#include <algorithm>

using namespace std;
#define MAX_SITE 28
#define MAX_LEVEL 3
#define START 0
#define ESTATE 1
#define CHANCE -2
#define FORTUNE -1
#ifndef _SITE_H_
#define _SITE_H_

class Site{
public:
// 物件位置，物件名稱，物件類型，初始價格，階段0過路費，階段1過路費，階段2過路費，階段3過路費，房產等級，擁有者、路障
	Site(int, string, int, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = -1, bool = false);
	Site(const Site& copy);
	//行為
	

	
//protected:
	// 變數
	int location;
	string name;
	int type;
	int firstPrice;
	int initialToll;
	int firstStageToll;
	int secondStageToll;
	int thirdStageToll;

	int estateLevel;
	int owner;
	//被擺放的道具
	bool barrier;

};

#endif // !_SITE_H_

