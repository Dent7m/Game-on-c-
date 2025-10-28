#include <iostream>
#include "windows.h"

using namespace std;

//������������ �������:
// private - ���������, ��������� ������ � ��������� � ������� �� ��������� ������ ������
// protected - ����������, ����� ���������� �������� � ������ � ������ ����������, �� �� ������������ � �������� ������ ���������
// public - ���������, �������������, ����� ������������ �����

//������� ����� - ����������� (����� � �������� ��� ������ �����������)
class Npc
{
protected: //����������� 0 ���������� (���� ������ ������ ������ �������� � ����������), �� ��� ��� �� ���� ������ � �������� ������ ���������
    string name{ "��������" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
public: //��������� ����������� ������ (������������ ����� ����� � ����� �����)
    virtual void GetInfo() //����� ������
    {
        cout << "��� - " << name << endl;
        cout << "�������� - " << health << endl;
        cout << "���� - " << damage << endl;
    }
    virtual void Create() {};
};

//������������ - ������������� ��������� ������� � ������� ������ ��������� (parent), ������� �����������(child)
class Warrior : public virtual Npc //������������ � ������������� ������� public
{
protected: //����������� 0 (��������� - ����������, ������ � �����, ������ ������ ������)
    unsigned short strenght{ 31 };
    string weapons[4] = { "������", "�������", "������", "���" };
public:
    //����������� - �����, ������� ���������� � ������ �������� ���������� ������ (������� ������� � �������� ������ ��������� �� �����)

    Warrior() //����������� �� ���������, ����� ��� ����������
    {
        name = "����";
        health = 35;
        damage = 10;
    }
    //��������� �����������
    Warrior(string name, unsigned int health, float damage)
    {
        cout << "��������� ����������� �����" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetWeapons()
    {
        cout << name << " ���� � ���� " << weapons[lvl - 1];
    }
    void GetInfo() override //����������� (���������� ��� ������)
    {
        Npc::GetInfo();
        cout << "���� - " << strenght << endl;
        cout << "��������� ������ - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << weapons[i] << endl;
        }
    }
    void Create() override
    {
        cout << "�� ������� �����" << endl;
        cout << "������� ��� ���������\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    //���������� ����������
    //���������� ��������� ��������� (==)
    bool operator == (const Warrior& warrior) const
    {
        return ((warrior.damage == this->damage) && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    }
    //���������� - �����, ������� ���������� ������������� ��� ������������� ������
    //��� ��������� ������ � ����������� ������ (������ ������� �������)

    ~Warrior() //���������� ������ ��� ����������
    {
        cout << endl;
        cout << name << " ��� ������� �������" << endl;
    }
};

//virtual - ������� ������������� �������, ������� ��� ���� ��� ����� �������� �� ���������

class Wizard : public virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "�������", "���������� ������", "�������� ���", "����������� �����" };
public:
    Wizard()
    {
        name = "���������";
        health = 23;
        damage = 15;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "��������� ����������� ����������" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    void GetInfo() override //����������� (���������� ��� ������)
    {
        Npc::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� � ����� ���������� - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void CastSpell()
    {
        cout << name << " ��������� " << spell[lvl - 1] << endl;
    }
    void Create() override
    {
        cout << "�� ������� ����������" << endl;
        cout << "������� ��� ���������\t";
        cin >> name;
        GetInfo();
        CastSpell();
    }
    Wizard operator + (const Wizard& wizard) const
    {
        return Wizard(this->name, (this->health + wizard.health), (this->damage + wizard.damage));
    }
    ~Wizard() //���������� ������ ��� ����������
    {
        cout << endl;
        cout << name << " �������� ���" << endl;
    }
};

//������������� ������������
class Paladin : public Warrior, public Wizard
//��������� ���������������� ����� ����������� ����� �������
{
public:
    Paladin()
    {
        name = "�������";
        health = 25;
        damage = 12;
        strenght = 27;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void Create() override
    {
        cout << "�� ������� ��������" << endl;
        cout << "������� ��� ���������\t";
        cin >> name;
        GetInfo();
        CastSpell();
        GetWeapons();
    }
};

class Player
{
public:
    void Create(Npc* player)
    {
        player->Create();
    }
};

unsigned short GetChoice(unsigned short first, unsigned short last);

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Warrior* warrior = new Warrior();
    Warrior* warrior2 = new Warrior();
    
    cout << (*warrior == *warrior2) << endl;

    Wizard* wizard = new Wizard();
    Wizard* wizard2 = new Wizard();
    Wizard* megaWizard = new Wizard();
   
    *megaWizard = *wizard + *wizard2;
    megaWizard->GetInfo();

    Paladin* paladin = new Paladin();
    Player* player = new Player();

    cout << "������, ������\n������� � ������ � �������� � ����\n";
    cout << "�� ������� ���? (1 - ����� ��������, 2 - ���������)\n";

    unsigned short choice = GetChoice(1, 2); 

    if (choice == 1)
    {
        cout << "�������� � ����� �������\n1 - ����\n2 - ���������\n3 - �������\n";
        choice = GetChoice(1, 3); 
        switch (choice)
        {
        case 1:
            player->Create(warrior);
            delete wizard;
            delete paladin;
            break;
        case 2:
            player->Create(wizard);
            delete warrior;
            delete paladin;
            break;
        case 3:
            player->Create(paladin);
            delete warrior;
            delete wizard;
            break;
        }
    }
    if (choice == 2)
    {
       
        cout << "�������� ���������..." << endl;
        delete warrior;
        delete warrior2;
        delete wizard;
        delete wizard2;
        delete megaWizard;
        delete paladin;
    }


   
    return 0;
}

unsigned short GetChoice(unsigned short first, unsigned short last) 
{
    unsigned short choice;
    cin >> choice;
    while (choice < first || choice > last) {
        cout << "�������� ����! ������� ����� �� " << first << " �� " << last;
        cout << endl;
        cin >> choice;
    }
    return choice;
}