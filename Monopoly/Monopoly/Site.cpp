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
}

// �����m�A����W�١A���������A��l����A���q0�L���O�A���q1�L���O�A���q2�L���O�A���q3�L���O
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