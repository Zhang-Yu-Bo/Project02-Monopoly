#pragma once
#include "Site.h"
#include <vector>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player{
public:
	// ���a�s���A�Ҧb��m�A�֦�����
	Player(int, int, int);
	//�x�s�O�_�����D�㪺�ܼ�
	int barrier;
	int playerID;
	int location;
	int money;
	int cannotMove;//�N���ಾ�ʦh�֦^�X�A0�N��i�H����
	vector<Site> estate;
	//�欰
	//���l(�^�ǻ�F�h��) int RollDice();
	
	//����
	///��L�_�I�O�_����
		//�����߰ݪ�(YN)
		//�ɯũв�
		//�Цa�����(estate)���� bool BuyAHouse(vector<Site>);�^�ǬO�_�ʶR���\
		//����(�D��)��m

private:
	
};

#endif // !_PLAYER_H_

