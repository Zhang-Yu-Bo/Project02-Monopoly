#pragma once
#include <string>

using namespace std;

#ifndef _SITE_H_
#define _SITE_H_

class Site{
public:
// �����m�A����W�١A���������A��l����A���q0�L���O�A���q1�L���O�A���q2�L���O�A���q3�L���O�A�в����šA�֦���
	Site(int, string, int, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = -1);
	//�欰
	
//protected:
	// �ܼ�
	int location;
	string name;
	int type;
	int firstPrice;
	int tolls;
	int firstTolls;
	int secondTolls;
	int thirdTolls;
	int estateLevel;
	int owner;
};

#endif // !_SITE_H_

