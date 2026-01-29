#pragma once
#include "MainClass.h"
#include "string"

class Sentinel : public virtual Npc
{
protected:  
    unsigned short strenght{ 430 };
    string weapons[4] = { "Меч", "Пистолет", "Двуручный меч", "Древковое оружие" };
public:
    bool Save() override;
    bool Load() override;
    Sentinel();
    Sentinel(string name, unsigned int health, float damage);

    void GetWeapons();
    void GetInfo();
    void Create() override;

    bool operator == (const Sentinel& sentinel) const;
    Sentinel& operator = (const Npc& npc);

    ~Sentinel();
};

class TheCaster : public virtual Npc
{

    class Art
    {
    protected:
        string name{ "Ориджинивое искусство" };
        unsigned short damage{ 0 };
        unsigned short price{ 0 };
        bool isCurse{ false };
        int timeCast{ 0 };

    public:
        Art(string name = "Ориджинивое искусство", unsigned short damage = 0,
            unsigned short price = 0, bool isCurse = false, int timeCast = 0);

        string GetName() const { return name; }
        unsigned short GetDamage() const { return damage; }
        unsigned short GetPrice() const { return price; }
        bool IsCurse() const { return isCurse; }
        int GetTimeCast() const { return timeCast; }

        unsigned short CastArt();
    };
protected:
    unsigned short intellect = 380;
    Art arts[5] = {
        Art("Сингулярность скорби", 450,150,false,50),
        Art("Фантомная Кистевая рост", 0,40,false,100),
        Art("Катализатор Ржавчины", 15,70,true,10),
        Art("Реверберационыый Кокон", 0,200,false,5),
        Art("Квантовая нить судьбы", 0,100,false,15),
    };
public:
    TheCaster();
    TheCaster(string name, unsigned int health, float damage);
    void GetArts();
    void GetInfo();
    void GetArtInfo();
    void Create() override;
    bool operator == (const TheCaster& thecaster) const;
    void operator = (Npc npc);
    bool Save() override;
    bool Load() override;
    ~TheCaster(); //деструктор всегда без аргументов
};

class Stormtrooper : public Sentinel, public TheCaster
{
public:
    Stormtrooper();
    void GetInfo();
    void Create() override;
    bool operator == (const Stormtrooper& stormtrooper) const;
    Stormtrooper& operator = (const Npc& npc);
    bool Save() override;
    bool Load() override;
};