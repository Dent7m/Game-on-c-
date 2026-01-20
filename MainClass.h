#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Npc
{
protected: //модификатор 0 защищенный (дает доступ внутри класса родителя и наследника)
    //но все еще не дает доступ в основном потоке программы

    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };

public:    //публичный модификатор доступ (использовать метод можно в любом месте)
    string GetName() const;
    unsigned int GetHealth() const;
    float GetDamage() const;
    unsigned int GetLvl() const;
    virtual void GetInfo();
    virtual void Create() {};

    virtual bool Save();
    virtual bool Load();
    virtual ~Npc() = default; //default - по умолчанию, чтобы не писать {} тело пустое
};
class Player
{
private:
    unique_ptr<Npc> currentCharacter{ nullptr }; //unique_ptr уникальный указатель, указывает на один объект
public:
    void Create(unique_ptr<Npc> player);
    void Create();
    bool Save();
    bool Load(unique_ptr<Npc> player);
    Npc* GetCharacter();
};
