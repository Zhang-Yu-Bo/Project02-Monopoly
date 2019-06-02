#include "Site.h"

Site::Site(int location, string name, int type, int firstPrice, int tolls, int firstTolls, int secondTolls, int thirdTolls, int estateLevel, int owner, bool barrier) {
	this->location = location;
	this->name = name;
	this->type = type;
	this->firstPrice = firstPrice;
	this->initialToll = tolls;
	this->firstStageToll = firstTolls;
	this->secondStageToll = secondTolls;
	this->thirdStageToll = thirdTolls;
	this->estateLevel = estateLevel;
	this->owner = owner;
	this->barrier = barrier;
}

Site::Site(const Site& copy){
	location = copy.location;
	name = copy.name;
	type = copy.type;
	firstPrice = copy.firstPrice;
	initialToll = copy.initialToll;
	firstStageToll = copy.firstStageToll;
	secondStageToll = copy.secondStageToll;
	thirdStageToll = copy.thirdStageToll;
	estateLevel = copy.estateLevel;
	owner = copy.owner;
	barrier = copy.barrier;
}
