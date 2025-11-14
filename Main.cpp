#include <iostream>
#include "windows.h"
#include "MainClass (1).h"
#include "BasicClasses (1).h"
#include "Evil.h"
#include "Main (1).h"

using namespace std;

/*class Product
{
public: Product() = default;
};

class Bread : public Product
{
public: Bread() = default;
};

class Chips : public Product
{
public: Chips() = default;
};

class Creator
{
public: 
    Creator() = default;
    virtual Product FactoryMethod() { return Product(); }
};

class BreadCreator : Creator
{
public:
    BreadCreator() = default;
    Product FactoryMethod() override { return Bread(); }
};
class ChipsCreator : Creator
{
public:
    ChipsCreator() = default;
    Product FactoryMethod() override { return Chips(); }
};*/ //пример написания

enum class ValueQuality
{
    мусор, обычное, редкое, легендарное, мифическое //эквивалент перечисления чисел
};

enum class WaponClass
{
   алебарда, клеймор, катана, лук, арбалет
};
enum class SpalloClass
{
    кровавый_дождь, метеор, святое_солнце, испепеляющий_гимн, хор_поднебесья
};

enum class CharacterType
{
        UNKNOWN = 0,
        WARRIOR,
        WIZARD,
        PALADIN
};

struct Wapon
{
    string name{ "Оружие" };
    WaponClass wclass = WaponClass::алебарда;
    unsigned int price { 0 };
    string valueSite[5]{ "Алебарда","Клеймор","Катана","Лук","Арбалет" };
    string site{ NULL };
    unsigned short damage{ 1 };
    Wapon(WaponClass wclass)
    {
        switch (wclass)
        {
        case WaponClass::алебарда:
            cout << "Алебарда\n";
            break;
        case WaponClass::клеймор:
            cout << "Клеймор\n";
            break;
        case WaponClass::катана:
            cout << "Катана\n";
            break;
        case WaponClass::лук:
            cout << "Лук\n";
            break;
        case WaponClass::арбалет:
            cout << "Арбалет\n";
            break;
        default:
            break;
        }
    };
};
struct Spallo
{
    string name{ "Магия" };
    SpalloClass sclass = SpalloClass::кровавый_дождь;
    unsigned int price{ 0 };
    Spallo(SpalloClass sclass)
    {
        switch (sclass)
        {
        case SpalloClass::кровавый_дождь:
            cout << "\n";
            break;
        case SpalloClass::метеор:
            cout << "\n";
            break;
        case SpalloClass::святое_солнце:
            cout << "\n";
            break;
        case SpalloClass::испепеляющий_гимн:
            cout << "\n";
            break;
        case SpalloClass::хор_поднебесья:
            cout << "\n";
            break;
        default:
            break;
        }
    };
};
//отличие struct от class
/**/
struct Treasure //по умолчанию все внутри public
{
    string name{ "добыча" };
    ValueQuality quality = ValueQuality::мусор;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::мусор:
            cout << "Плохое качество\n";
            break;
        case ValueQuality::обычное:
            cout << "Обычное качество\n";
            break;
        case ValueQuality::редкое:
            cout << "Хорошое качество\n";
            break;
        case ValueQuality::легендарное:
            cout << "Отличное качество\n";
            break;
        case ValueQuality::мифическое:
            cout << "Божественное качество\n";
            break;
        default:
            break;
        }
    }
};
struct Cloth : Treasure //наследование по умолчанию public
{
    Cloth(ValueQuality quaity) : Treasure(quality) {};
    string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
    string site{ NULL };
    unsigned short armor{ 1 };
};

/*
class Treasure //все по умолчанию внутри private
{
public:
    string name{ "добыча" };
    string quality[5]{ "мусор","обычное","редкое","легендарное","мифическое" };
    unsigned int price{ 0 };
};
class Cloth : Treasure //наследование по умолчанию private
{
    string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
    string site{ NULL };
    unsigned short armor{ 1 };
};*/

/*unique_ptr<Npc>CreateWapon(WaponClass wclass)
{
    switch (wclass)
    {
    case WaponClass::алебарда:
        //return make_unique<алебарда>()
        break;
    case WaponClass::клеймор:
        break;
    case WaponClass::катана:
        break;
    case WaponClass::лук:
        break;
    case WaponClass::арбалет:
        break;
    default:
        invalid_argument("Неизвестный тип оружия");
        break;
    }
}*/

unique_ptr<Npc> CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::UNKNOWN:
        return make_unique<Npc>();
        break;
    case CharacterType::WARRIOR:
        return make_unique<Warrior>();
        break;
    case CharacterType::WIZARD:
        return make_unique<Wizard>();
        break;
    case CharacterType::PALADIN:
        return make_unique<Paladin>();
        break;
    default:
        invalid_argument("Неизветсный тип персонажа");
        break;
    }
}

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*Treasure treasure;
    treasure.name = "древняя тарелка";
    treasure.price = 30;
    treasure.quality = treasure.valuequality[3];
    cout << treasure.name << '\n' << treasure.price << '\n' << treasure.quality << '\n';*/
    
    /*Cloth cloth(ValueQuality::мифическое);
    cloth.armor = 10;
    cloth.site = cloth.valueSite[2];
    cloth.name = "Шлем лорда повелителя";
    cloth.price = 50;
    cout << cloth.name << '\n' << cloth.site << '\n' << cloth.armor << '\n' << cloth.price << '\n';

    Wapon wapon(WaponClass::катана);
    wapon.damage = 10;
    wapon.site = wapon.valueSite[2];
    wapon.name = "Кровавый дайме";
    wapon.price = 50;
    cout << wapon.name << '\n' << wapon.site << '\n' << wapon.damage << '\n' << wapon.price << '\n';*/

    Player* player = new Player();

    cout << "Привет, путник\nПрисядь у костра и расскажи о себе\n";
    cout << "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n";
    if (TestChoise(2, "Наверное ты ошибся, повтори снова\n"))
    {
        cout << "Расскажи о своих навыках\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n";
        unique_ptr<Npc> character;
        switch (TestChoise(3, "Такого еще не было в наших краях\nНе мог бы ты повторить\n"))
        {
        case 1:
            character = CreateCharacter(CharacterType::WARRIOR);
            break;
        case 2:
            character = CreateCharacter(CharacterType::WIZARD);
            break;
        case 3:
            character = CreateCharacter(CharacterType::PALADIN);
            break;
        }
        player->Create(move(character));
    }
    else
    {
        ifstream loadSystem("save.bin", ios::binary);
        if (!loadSystem.is_open())
        {
            {
                size_t nameLenght;
                loadSystem.read(reinterpret_cast<char*>(&nameLenght), sizeof(nameLenght));
                char* buffer = new char[nameLenght + 1];
                loadSystem.read(buffer, nameLenght);
                buffer[nameLenght] = '\0';
               
                return loadSystem.good();
            }
        }
    }
    /*unsigned short choise = 1;
    cin >> choise;
    while (choise > 2 || choise < 1)
    {
        cout << "Наверное ты ошибся, повтори снова\n";
        cin >> choise;
    }
    if (choise == 1)
    {
        cout << "Расскажи о своих навыках\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n";
        cin >> choise;
        while (choise > 3 || choise < 1)
        {
            cout << "Такого еще не было в наших краях\nНе мог бы ты повторить\n";
            cin >> choise;
        }

        switch (choise)
        {
        case 1: {
            player->Create(warrior);
            delete wizard;
            wizard = nullptr;
            delete paladin;
            paladin = nullptr;
            break;
        }
        case 2: {
            player->Create(wizard);
            delete warrior;
            warrior = nullptr;
            delete paladin;
            paladin = nullptr;
            break;
        }
        case 3: {
            player->Create(paladin);
            delete warrior;
            warrior = nullptr;
            delete wizard;
            wizard = nullptr;
            break;
        }
        }

    }

    else
    {
        player->Load(warrior);
    }

    cout << "сделаем остановку тут?\n\t1 - сохранить игру\n\t2 - продолжить\n";
    cin >> choise;
    if (choise == 1)
    {
        if (warrior != nullptr) player->Save(warrior);
        if (wizard != nullptr) player->Save(wizard);
        if (paladin != nullptr) player->Save(paladin);
    }*/



    return 0;
}

unsigned short GetChoice(unsigned short first, unsigned short last)
{
    unsigned short choice;
    cin >> choice;
    while (choice < first || choice > last) {
        cout << "Неверный ввод! Введите число от " << first << " до " << last;
        cout << endl;
        cin >> choice;
    }
    return choice;

}
