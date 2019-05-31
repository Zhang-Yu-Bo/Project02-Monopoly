#include "Site.h"

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
