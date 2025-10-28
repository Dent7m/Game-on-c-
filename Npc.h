#pragma once
#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <string>

class Npc {
protected:
	std::string name;
	int health;
	float damage;
	short lvl;
public:
	Npc(const std::string n, int h, float d, short l);
	void Create();
	void GetInfo();
};

#endif //!NPC