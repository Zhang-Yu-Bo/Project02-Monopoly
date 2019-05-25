#include "Site.h"

Site::Site() {
	// initial condition
	this->location = 0;
	this->name = "起點";
	this->type = 0;
	this->firstPrice = 0;
	this->tolls = 0;
	this->firstTolls = 0;
	this->secondTolls = 0;
	this->thirdTolls = 0;
}

// 物件位置，物件名稱，物件類型，初始價格，階段0過路費，階段1過路費，階段2過路費，階段3過路費
Site::Site(int location, string name, int type, int firstPrice = 0, int tolls = 0, int firstTolls = 0, int secondTolls = 0, int thirdTolls = 0) {
	this->location = location;
	this->name = name;
	this->type = type;
	this->firstPrice = firstPrice;
	this->tolls = tolls;
	this->firstTolls = firstPrice;
	this->secondTolls = secondTolls;
	this->thirdTolls = thirdTolls;
}

int Site::getLocation() const {
	return this->location;
}

string Site::getName() const {
	return this->name;
}

int Site::getType() const {
	return this->type;
}

int Site::getFirstPrice() const {
	return this->firstPrice;
}

int Site::getTolls() const {
	return this->tolls;
}

int Site::getFirstTolls() const {
	return this->firstTolls;
}

int Site::getSecondTolls() const {
	return this->secondTolls;
}

int Site::getThirdTolls() const {
	return this->thirdTolls;
}