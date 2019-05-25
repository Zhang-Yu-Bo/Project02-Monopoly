#pragma once
#include <string>

using namespace std;

#ifndef _SITE_H_
#define _SITE_H_

class Site
{
public:
	Site();
	// �����m�A����W�١A���������A��l����A���q0�L���O�A���q1�L���O�A���q2�L���O�A���q3�L���O
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

