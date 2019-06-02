#include "Player.h"

Player::Player(int playerID, int location, int money, int barrier = 0, int controlledDice = 0, int cannotMove = 0) {
	this->playerID = playerID;
	this->location = location;
	this->money = money;
	this->barrier = barrier;
	this->controlledDice = controlledDice;
	this->cannotMove = cannotMove;
}

int Player::RollADice(){
	return (int)((rand() / (RAND_MAX + 1.0)) * 6 + 1);

}

void Player::Move(int steps, vector<Site>& sites){
	int destination = this->location + steps;
	if (destination >= MAX_SITE) {//經過或踩到起點
		destination -= MAX_SITE;
		auto siteIter = sites.begin();
		if (location + 1 < MAX_SITE) {
			for (siteIter = (sites.begin() + (this->location + 1)); siteIter < sites.end(); siteIter++) {
				if (siteIter->barrier == true) {//路徑上有路障
					siteIter->barrier = false;
					destination = siteIter->location;
					break;
				}
			}
		}
		else {
			siteIter = sites.end();
		}
		for (siteIter = (sites.begin()); siteIter <= (sites.begin() + destination); siteIter++) {
			if (siteIter->barrier == true) {//路徑上有路障
				siteIter->barrier = false;
				destination = siteIter->location;
				break;			
			}
		}	
	}
	else {
		for (auto siteIter = (sites.begin() + (this->location + 1)); siteIter <= (sites.begin() + destination); siteIter++) {
			if (siteIter->barrier) {//路徑上有路障
				siteIter->barrier = false;
				destination = siteIter->location;
				break;
			}
		}
	}
	this->location = destination;
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
	if (sites[position].owner != -1) {
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
}

void Player::PlaceABarrier(const int position, vector<Site>&sites){
	sites[position].barrier = true;
}
