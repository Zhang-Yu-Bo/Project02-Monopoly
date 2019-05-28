#pragma once
#include "Display.h"
#include "Site.h"
#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <fstream>

#define KEYBOARD_UP 72
#define KEYBOARD_DOWN 80
#define KEYBOARD_LEFT 75
#define KEYBOARD_RIGHT 77
#define KEYBOARD_ENTER 13
#define KEYBOARD_ESCAPE 27

using namespace std;

#ifndef _GAME_H_
#define _GAME_H_

class Game
{
public:
	// �a���ɦW
	Game(string);
	void start();
	bool isGameAlive();
	void process();
	//�欰
	//���a����call player�̪�function
	//����l���欰
		//���D�aOR�L�D�aOR�\���(���|�B�R�B)
		//�L:�O�_�ʶR(�߰�)
			//�O:call player�̪�function
		//��:�֪�
			//�O�H��:�I��
			//�ۤv��:�O�_�ɯ�(�Τw�̰�������ɯ�)(�߰�)call player�̪�function
		//�\���:����
private:
	// ...�����禡
	void loadMap();
	void openOptions();
	// ...�ܼ�
	string mapName; //�a�ϦW�١A�PmapFileName���P
	int allPlayers; //�`�@�h�֪��a
	string mapFileName;
	bool gameLife;
	vector<Site> sites;
	vector<Player> players;
	// �֪��^�X
	int whosTurn;
	// �Ѿl�^�X
	int remainTurn;

};

#endif // !_GAME_H_

