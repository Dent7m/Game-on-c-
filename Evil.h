#pragma once
#include "MainClass.h"

class Evil : public Npc {
public:
    Evil(string name);
    Evil(string name, int health) : Evil(name) {};
    Evil(string name, int health, int damage) : Evil(name, health) {};
    void GetInfo() override;
};