#include "Player.h"

Player::Player(int playerID, int location, int money, int barrier = 0, int controlledDice = 0, int cannotMove = 0) {
	this->playerID = playerID;
	this->location = location;
	this->money = money;
	this->barrier = barrier;
	this->controlledDice = controlledDice;
	this->cannotMove = cannotMove;
}

int Player::RollADice()
{
	return (int)((rand() / (RAND_MAX + 1.0)) * (6 - 1 + 1.0) + 1);
}

void Player::Move(int steps)
{
	if (location + steps >= MAX_SITE) {//經過或踩到起點
		location += (steps - MAX_SITE);
	}
	else {
		location += steps;
	}
}

void Player::ProchaseAnEstate(const int position, vector<Site>& sites){
	money -= sites[position].firstPrice;
	sites[position].owner = playerID;
	estate.push_back(sites[position]);
}

void Player::UpgradeAnEstate(const int position, vector<Site>&sites){
	money -= 0;//upgrade free for now
	sites[position].estateLevel++;

}

void Player::PayForTheToll(const int position, const vector<Site>& sites ,vector<Player>& players){
	int tax = 0;
	switch (sites[position].estateLevel){
	case 0:
		tax = sites[position].initialToll;
		break;
	case 1:
		tax = sites[position].firstStageToll;
		break; 
	case 2:
		tax = sites[position].secondStageToll;
		break; 
	case 3:
		tax = sites[position].thirdStageToll;
		break;
	default:
		break;
	}
	this->money -= tax;
	players[sites[position].owner].money += tax;
	
}
