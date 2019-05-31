#pragma once
#include <string>

using namespace std;
#define MAX_SITE 28
#define MAX_LEVEL 3
#define START 0
#define ESTATE 1
#define CHANCE -1
#define FORTUNE -2
#ifndef _SITE_H_
#define _SITE_H_

class Site{
public:
// 物件位置，物件名稱，物件類型，初始價格，階段0過路費，階段1過路費，階段2過路費，階段3過路費，房產等級，擁有者
	Site(int, string, int, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = -1);
	Site(const Site& copy) {
		location = copy.location;
		name = copy.name;
		type = copy.type;
		firstPrice = copy.firstPrice;
		tolls = copy.tolls;
		firstTolls = copy.firstTolls;
		secondTolls = copy.secondTolls;
		thirdTolls = copy.thirdTolls;
		estateLevel = copy.estateLevel;
		owner = copy.owner;
	}
	//行為

	
//protected:
	// 變數
	int location;
	string name;
	int type;
	int firstPrice;
	//以下四項請求更改為vector
	int tolls;
	int firstTolls;
	int secondTolls;
	int thirdTolls;

	int estateLevel;
	int owner;
};

#endif // !_SITE_H_

