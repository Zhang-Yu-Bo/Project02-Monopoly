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
// �����m�A����W�١A���������A��l����A���q0�L���O�A���q1�L���O�A���q2�L���O�A���q3�L���O�A�в����šA�֦���
	Site(int, string, int, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = -1);
	Site(const Site& copy);
	//�欰
	void FCEvent();

	
//protected:
	// �ܼ�
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
};

#endif // !_SITE_H_

