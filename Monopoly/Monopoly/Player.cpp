#include "Player.h"

Player::Player(int playerID, int location, int money) {
	this->playerID = playerID;
	this->location = location;
	this->money = money;
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

void Player::ProchaseAnEstate(int position, vector<Site>& sites){
	money -= sites[position].firstPrice;
	sites[position].owner = playerID;
	estate.push_back(sites[position]);
}

void Player::UpgradeAnEstate(int position, vector<Site>&sites){

}
