#pragma once
#include "Site.h"
#include <cstdlib>
#include <vector>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player{
public:
	// ���a�s���A�Ҧb��m�A�֦�����
	Player(int, int, int, int, int, int);
	int playerID;	
	int location;
	int money;
	//tolls number(��Ȭ������ƶq)
	int barrier;
	int controlledDice;
	int cannotMove;//�N���ಾ�ʦh�֦^�X�A0�N��i�H����
	vector<Site> estate;
	//�欰
	
	int RollADice();//���l(�^�ǻ�F�h��) 
	void Move(int, vector<Site>&);//���a����(�ǤJ���ʨB��,site)
	void ProchaseAnEstate(const int, vector<Site>&);//���a�ʶR�в�(�ǤJ�в��a�I,game�̪�vector<Sites>&�ä@�֭ק�)
	void UpgradeAnEstate(const int, vector<Site>&);//���a�ɯũв�(�ǤJ�в��a�I,game�̪�vector<Sites>&�ä@�֭ק�)
	void PayForTheToll(const int, const vector<Site>&, vector<Player>&);
	void PlaceABarrier(const int, vector<Site>&);
	void FCEvents(const int);//�ǤJ���|OR�R�B
	///��L�_�I�O�_����
		//����(�D��)��m
};

#endif // !_PLAYER_H_

