#include"Player.h"
/*
CHANCE:
1. 2. 3.
	 �M�p!��o1500��
4. 5. (��o�@�ӱ���A���l��300*N�� N��1~10�ü�)
	�ٴ��ߪ��ڡAN��~�X�f�A��o����@���A�l��300N��
6. 
	�b�A���g�a�W���X�F�����P�۪o�A�C���@�ɩв���o1000��
7. 8.  
	�ٴ��ߪ��ڡA�s�|�P§�˳��S���A�l��2000��
FORTUNE:
1. 2.
	�ۺN�p!�V��L���a����1000��
3. 
	����ֳh�I�t�Z�A�̳h�a���a�V�̴I�����a����3500��
4. 5. (�L�k����1�^�X�A��o300��)
	���A������10�p�ɡA���v 300���A�L�k����1�^�X
6. 7. 8. 
	�A�������Q��G8�H�A��o���٤@��
*/

string Player::FCEvents(const int c ,vector<Player>& players) {
	int r = (int)((rand() / (RAND_MAX + 1.0)) * 7 + 1);
	int n = (int)((rand() / (RAND_MAX + 1.0)) * 10 + 1);
	int estateSize = estate.size();
	int pID = playerID, m = 0;
	stringstream ss;
	string str;
	if (c == CHANCE) {//���|
		switch (r){
		case 1: case 2: case 3:
			str = "�M�p!��o1500��";
			money += 1500;
			return str;
			break;
		case 4:	case 5:
			
			if (n < 4) {
				ss << "�ٴ��ߪ��ڡA" << n << "��~�X�f�A��o����@���A�l�� " << 300 * n << "��";
			}
			else {
				ss << "�ٴ��ߪ��ڡA" << n << "��~�X�f�A��o����@���A�l��" << 300 * n << "��";
			}
			controlledDice++;
			money -= (300 * n);
			return ss.str();
			break;
		case 6:
			ss << "�b�A���g�a�W���X�F�����P�۪o�A" << estateSize << "�ɩв��O�A��o" << 1000 * estateSize << "��";
			money += (1000 * estateSize);
			return ss.str();
			break;
		case 7:	case 8:
			str = "�ٴ��ߪ��ڡA�s�|�P§�˳��S���A�l��2000��";
			money -= 2000;
			return str;
			break;
		default:
			break;
		}
	}
	else if (c == FORTUNE) {//�R�B
		vector<pair<int,int>> v;//ID,money
		switch (r) {
		case 1:	case 2:
			str = "�ۺN�p!�V��L���a����1000��";
			for (int i = 0; i < players.size(); i++) {
				if (i != pID && players[i].money > 0) {
					players[pID].money -= 1000;
					m += 1000;
				}
			}
			money += m;
			return str;
			break;
		case 3:
			str = "����ֳh�I�t�Z�A�̳h�a���a�V�̴I�����a����3500��";
			for (int i = 0; i < players.size(); i++) {
				if (players[i].money > 0) {
					v.push_back(make_pair(players[i].playerID, players[i].money));
				}
			}
			for (int i = 0; i < v.size() - 1; i++) {
				for (int j = 0; j < v.size() - i - 1; j++) {
					if (v[j + 1].second < v[j].second) {
						swap(v[j],v[j+1]);
					}
				}
			}
			players[v[v.size() - 1].first].money -= 3500;
			players[v[0].first].money += 3500;
			return str;
			break;
		case 4:	case 5:
			str = "���A������10�p�ɡA���v 300���A�L�k����1�^�X";
			cannotMove++;
			money += 300;
			break;
		case 6:	case 7:	case 8:
			str = "�A�������Q��G8�H�A��o���٤@��";
			barrier++;
			return str;
			break;
		default:
			break;
		}
	}
}