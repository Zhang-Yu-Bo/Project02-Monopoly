#include "Site.h"

Site::Site() {
	// initial condition
	this->location = 0;
	this->name = "�_�I";
	this->type = 0;
	this->firstPrice = 0;
	this->tolls = 0;
	this->firstTolls = 0;
	this->secondTolls = 0;
	this->thirdTolls = 0;
	this->estateLevel = 0;
	this->owner = 0;
}

// �����m�A����W�١A���������A��l����A���q0�L���O�A���q1�L���O�A���q2�L���O�A���q3�L���O
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