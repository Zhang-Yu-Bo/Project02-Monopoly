#pragma once
#include <string>

using namespace std;

#ifndef _SITE_H_
#define _SITE_H_

class Site
{
public:
	Site();
	// 物件位置，物件名稱，物件類型，初始價格，階段0過路費，階段1過路費，階段2過路費，階段3過路費
	Site(int, string, int, int, int, int, int, int);
	int getLocation() const;
	string getName() const;
	int getType() const;
	int getFirstPrice() const;
	int getTolls() const;
	int getFirstTolls() const;
	int getSecondTolls() const;
	int getThirdTolls() const;
	int getEstateLevel() const;
private:
	int location;
	string name;
	int type;
	int firstPrice;
	int tolls;
	int firstTolls;
	int secondTolls;
	int thirdTolls;
	int estateLevel;
};

#endif // !_SITE_H_

