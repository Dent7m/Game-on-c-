#include "BasicClasses.h"

bool Sentinel::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (Npc::Save())
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

};
bool Sentinel::Load()
{
    ifstream loadSystem("save.bin", ios::binary);

    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));

    }
    else
    {
        cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
        return false;
    }
    loadSystem.close();
    return true;


};
Sentinel::Sentinel() //конструктор по умолчанию, когда нет аргументов
{
    name = "Страж";
    health = 1500;
    damage = 90;
}

Sentinel::Sentinel(string name, unsigned int health, float damage)
{
    cout << "Кастомный конструктор Стража" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Sentinel::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1];
}
void Sentinel::GetInfo()   //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Сила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << endl;
    }
}
void Sentinel::Create()
{
    cout << "Вы создали стража" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
bool Sentinel::operator == (const Sentinel& sentinel) const
{
    return (sentinel.damage == this->damage) &&
        (sentinel.health == this->health) &&
        (sentinel.strenght == this->strenght);
}
Sentinel& Sentinel::operator = (const Npc& npc)
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

Sentinel::~Sentinel()
{
    cout << name << "\nПоглощен Катастрофой" << endl;
}

TheCaster::Art::Art(string name, unsigned short damage,
    unsigned short price, bool isCurse, int timeCast)
    : name(name), damage(damage), price(price),
    isCurse(isCurse), timeCast(timeCast)
{
}

unsigned short TheCaster::Art::CastArt()
{
    return 0;
}

bool TheCaster::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (!Npc::Save())
        {
            cout << "Сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "Сохранение не удалось" << endl;
        return false;
    }
}
bool TheCaster::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&intellect), sizeof(intellect));
        loadSystem.close();
        return true;
    }
    else
    {
        cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
        return false;
    }
}
TheCaster::TheCaster()
{
    name = "Заклинатель";
    health = 1100;
    damage = 150;
}
TheCaster::TheCaster(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор заклинателя" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}
void TheCaster::GetArts()
{
    cout << name << " взял в руки ";
}
void TheCaster::GetInfo() //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Интеллект - " << intellect << endl;
    cout << "Доступные ориджинивые искусства - ";
   

}
void TheCaster::GetArtInfo()
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " Искусство: " << arts[i].GetName()
            << ", Урон: " << arts[i].GetDamage()
            << ", Цена: " << arts[i].GetPrice() << endl;
    }

}

void TheCaster::Create()
{
    cout << "Вы создали заклинателя" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();

}
bool TheCaster::operator == (const TheCaster& thecaster) const
{
    return ((thecaster.damage == this->damage) && (thecaster.health == this->health)
        && (thecaster.intellect == this->intellect));
}
void TheCaster::operator = (Npc npc)
{
    this->name = npc.GetName();
    this->name = npc.GetHealth();
    this->name = npc.GetDamage();
    this->name = npc.GetLvl();
}

TheCaster::~TheCaster() //деструктор всегда без аргументов
{
    cout << name << "\nПоглощен Катастрофой" << endl;
}

Stormtrooper::Stormtrooper()
{
    name = "Штурмовик";
    health = 1700;
    damage = 60;
    strenght = 410;
    intellect = 350;
}
void Stormtrooper::GetInfo()
{
    cout << "Имя - " << name << endl;
    cout << "Здоровье - " << health << endl;
    cout << "Урон - " << damage << endl;
    cout << "Сила - " << strenght << endl;
    cout << "Интеллект - " << intellect << endl;
}

void Stormtrooper::Create()
{
    cout << "Вы создали штурмовика" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();  
}

bool Stormtrooper::operator == (const Stormtrooper& stormtrooper) const
{
    return (stormtrooper.damage == this->damage) &&
        (stormtrooper.health == this->health) &&
        (stormtrooper.strenght == this->strenght) &&
        (stormtrooper.intellect == this->intellect);
}

Stormtrooper& Stormtrooper::operator = (const Npc& npc)
{
    if (this != &npc)
    {
        this->name = npc.GetName();
        this->health = npc.GetHealth();
        this->damage = npc.GetDamage();
        this->lvl = npc.GetLvl();
        this->strenght = 410;  
        this->intellect = 350; 
    }
    return *this;
}
bool Stormtrooper::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (!Npc::Save())
        {
            cout << "Сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
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

bool Stormtrooper::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&intellect), sizeof(intellect));
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));
        loadSystem.close();
        return true;
    }
    else
    {
        cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
        return false;
    }
}