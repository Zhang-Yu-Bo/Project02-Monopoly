#include"Player.h"
/*
CHANCE:
1. 2. 3.
	 和喵!獲得1500元
4. 5. (獲得一個控骰，但損失300*N元 N取1~10亂數)
	還敢氪金啊，N單才出貨，獲得控骰一顆，損失300N元
6. 
	在你的土地上挖出了黃金與石油，每有一棟房產獲得1000元
7. 8.  
	還敢氪金啊，連四星禮裝都沒有，損失2000元
FORTUNE:
1. 2.
	自摸喵!向其他玩家收取1000元
3. 
	為減少貧富差距，最貧窮玩家向最富有玩家索取3500元
4. 5. (無法移動1回合，獲得300元)
	伺服器維修10小時，補償 300元，無法移動1回合
6. 7. 8. 
	你４８４想當G8人，獲得路障一個
*/

string Player::FCEvents(const int c ,vector<Player>& players) {
	int r = (int)((rand() / (RAND_MAX + 1.0)) * 7 + 1);
	int n = (int)((rand() / (RAND_MAX + 1.0)) * 10 + 1);
	int estateSize = estate.size();
	int pID = playerID, m = 0;
	stringstream ss;
	string str;
	if (c == CHANCE) {//機會
		switch (r){
		case 1: case 2: case 3:
			str = "和喵!獲得1500元";
			money += 1500;
			return str;
			break;
		case 4:	case 5:
			
			if (n < 4) {
				ss << "還敢氪金啊，" << n << "單才出貨，獲得控骰一顆，損失 " << 300 * n << "元";
			}
			else {
				ss << "還敢氪金啊，" << n << "單才出貨，獲得控骰一顆，損失" << 300 * n << "元";
			}
			controlledDice++;
			money -= (300 * n);
			return ss.str();
			break;
		case 6:
			ss << "在你的土地上挖出了黃金與石油，" << estateSize << "棟房產令你獲得" << 1000 * estateSize << "元";
			money += (1000 * estateSize);
			return ss.str();
			break;
		case 7:	case 8:
			str = "還敢氪金啊，連四星禮裝都沒有，損失2000元";
			money -= 2000;
			return str;
			break;
		default:
			break;
		}
	}
	else if (c == FORTUNE) {//命運
		vector<pair<int,int>> v;//ID,money
		switch (r) {
		case 1:	case 2:
			str = "自摸喵!向其他玩家收取1000元";
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
			str = "為減少貧富差距，最貧窮玩家向最富有玩家索取3500元";
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
			str = "伺服器維修10小時，補償 300元，無法移動1回合";
			cannotMove++;
			money += 300;
			break;
		case 6:	case 7:	case 8:
			str = "你４８４想當G8人，獲得路障一個";
			barrier++;
			return str;
			break;
		default:
			break;
		}
	}
}