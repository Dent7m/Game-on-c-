#pragma once
#include "MainClass.h"

class Warrior : public virtual Npc 
{
protected:  
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    
    Warrior Load();
    Warrior();
    Warrior(string name, unsigned int health, float damage);
    void GetWeapons();
    void GetInfo() override;  
    void Create() override;
    bool operator == (const Warrior& warrior) const;
    void operator = (Npc npc);
    bool Save() override;

    ~Warrior(); 

};


class Wizard : public virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "вспышка", "магисческая стрела", "огненный шар", "метеоритный дождь" };
public:
   
    Wizard();
    Wizard(string name, unsigned int health, float damage);
    void GetInfo() override;
    void CastSpell();
    void Create() override;
    bool operator == (const Wizard& wizard) const;
    void operator = (Npc npc);
    bool Save() override;
    ~Wizard();
   

};


class Paladin : public Warrior, public Wizard
    
{
public:
   
    Paladin();
    void GetInfo() override;
    void Create() override;
    bool operator == (const Paladin& paladin) const;
    void operator = (Npc npc);
    bool Save() override;

    ~Paladin();
   
};
