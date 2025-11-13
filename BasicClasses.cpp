#include "BasicClasses.h"
#include "MainClass.cpp"

Warrior::Warrior() 
{
    name = "воин";
    health = 35;
    damage = 10;
}
Warrior::Warrior(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор война" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Warrior::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1];
}
void Warrior::GetInfo()   
{
    Npc::GetInfo();
    cout << "Сила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++) //нужно испроваить через условие
    {
        cout << weapons[i] << endl;
    }
}
void Warrior::Create()
{
    cout << "Вы создали война" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
bool Warrior::operator == (const Warrior& warrior) const
{
    return (warrior.damage == this->damage) && 
           (warrior.health == this->health) && 
           (warrior.strenght == this->strenght);
}
Warrior& Warrior::operator = (const Npc& npc) 
{
    if (this != &npc)
    {
        this->name = npc.GetName();
        this->health = npc.GetHealth();
        this->damage = npc.GetDamage();
        this->lvl = npc.GetLvl();
        return *this;
    }
}

bool Warrior::Save()
{
    if (Npc::Save())
    {
        ofstream saveSystem("save.bin", ios::binary);
        if (saveSystem.is_open())
        {
            if (!Npc::Save())
            {
                cout << "Сохранение не удалось" << endl;
                return false;
            }
            saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
          
            saveSystem.close();
            return true;
        }
        else
        {
            cout << "Сохранение не удалось" << endl;
            return false;
        }
    }
};

bool Warrior::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Связь с небом нарушена\nПамять утерена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));
    }
    else
    {
        cout << "Связь с небом нарушена\nПамять утерена" << endl;
        return false;
    }
    loadSystem.close();
    return true;
};

Warrior::~Warrior() 
{
    cout << name << " пал смертью храбрых" << endl;
}
