#pragma once
#include "Site.h"
#include <cstdlib>
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
	
	int RollADice();//���l(�^�ǻ�F�h��) 
	void Move(int);//���a����(�ǤJ���ʨB��)
	void ProchaseAnEstate(int, vector<Site>&);//���a�ʶR�в�(�ǤJ�в��a�I,game�̪�vector<Sites>&�ä@�֭ק�)
	void UpgradeAnEstate(int, vector<Site>&);//���a�ɯũв�(�ǤJ�в��a�I,game�̪�vector<Sites>&�ä@�֭ק�)
	///��L�_�I�O�_����

		//�����߰ݪ�(YN)
		//�ɯũв�
		//�Цa�����(estate)���� bool BuyAHouse(vector<Site>);�^�ǬO�_�ʶR���\
		//����(�D��)��m

	
};

#endif // !_PLAYER_H_

