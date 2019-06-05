#include "Player.h"
#include "Stock.h"

Player::Player(int playerID, int location, int money, int barrier = 0, int controlledDice = 0, int cannotMove = 0) {
	this->playerID = playerID;
	this->location = location;
	this->money = money;
	//this->barrier = barrier;
	this->barrier = 5;
	//this->controlledDice = controlledDice;
	this->controlledDice = 5;
	this->cannotMove = cannotMove;
	this->deposit = 0;
	this->loan = 0;
	this->stockNum[Stock::companyA] = 0;
	this->stockNum[Stock::companyB] = 0;
}

int Player::RollADice(){
	return (int)((rand() / (RAND_MAX + 1.0)) * 6 + 1);

}

bool Player::Move(int steps, vector<Site>& sites){
	int destination = this->location + steps;
	if (destination >= MAX_SITE) {//經過或踩到起點
		destination -= MAX_SITE;
		auto siteIter = sites.begin();
		if (location + 1 < MAX_SITE) {
			for (siteIter = (sites.begin() + (this->location + 1)); siteIter < sites.end(); siteIter++) {
				if (siteIter->barrier == true) {//路徑上有路障，回傳false
					siteIter->barrier = false;
					destination = siteIter->location;
					this->location = destination;
					return false;
				}
			}
		}
		for (siteIter = (sites.begin()); siteIter <= (sites.begin() + destination); siteIter++) {
			if (siteIter->barrier == true) {//路徑上有路障
				siteIter->barrier = false;
				destination = siteIter->location;
				this->location = destination;
				return false;
			}
		}	
	}
	else {
		for (auto siteIter = (sites.begin() + (this->location + 1)); siteIter <= (sites.begin() + destination); siteIter++) {
			if (siteIter->barrier == true) {//路徑上有路障
				siteIter->barrier = false;
				destination = siteIter->location;
				this->location = destination;
				return false;
			}
		}
	}
	this->location = destination;
	return true;
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
	barrier--;
}
