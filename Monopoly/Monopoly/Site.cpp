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
	this->estateLevel = 0;
	this->owner = 0;
}

// 物件位置，物件名稱，物件類型，初始價格，階段0過路費，階段1過路費，階段2過路費，階段3過路費
Site::Site(int location, string name, int type, int firstPrice, int tolls, int firstTolls, int secondTolls, int thirdTolls, int estateLevel, int owner) {
	this->location = location;
	this->name = name;
	this->type = type;
	this->firstPrice = firstPrice;
	this->tolls = tolls;
	this->firstTolls = firstPrice;
	this->secondTolls = secondTolls;
	this->thirdTolls = thirdTolls;
	this->estateLevel = estateLevel;
	this->owner = owner;
}