#pragma once
#include "Evil.h"

Evil::Evil(std::string name) {
	this->name = name;
	health = 10;
	damage = 5;
}
Evil::Evil(string name, int health) : Evil(name) {
	this->health = health;
}
Evil::Evil(string name, int health, int damage) : Evil(name, health) {
	this->damage = damage;
}

void Evil::GetInfo() {
	cout << endl;
	cout << "íà âàñ íàïàë " << name << endl;
	if (health >= 0 && damage < 0) {
		cout << "Çäîðîâüå - " << health << endl;
	}
	if (health < 0 && damage >= 0) {
		cout << "óðîí - " << damage << endl;
	}
	if (health >= 0 && damage >= 0) {
		cout << "Çäîðîâüå - " << health << endl;
		cout << "óðîí - " << damage << endl;
	}
}
