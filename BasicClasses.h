#pragma once
#include "MainClass.h"

//������������ - ������������� ��������� �������
// � ������� ������ ��������� (parent), ������� �����������(child)
class Warrior : public virtual Npc //������������ � ������������� ������� public
{
protected:  //����������� 0 (��������� - ����������, ������ � �����, ������ ������ ������)
    unsigned short strenght{ 31 };
    string weapons[4] = { "������", "�������", "������", "���" };
public:
    //����������� - �����, ������� ���������� � ������ �������� ����������
    //������ (������� ������� � �������� ������ ��������� �� �����)
    bool Save() override
    {


        if (Npc::Save())
        {
            ofstream saveSystem("save.bin", ios::binary);
            if (saveSystem.is_open())
            {

                saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
                for (int i = 0; i < 4; i++)
                {
                    saveSystem.write(reinterpret_cast<const char*>(&weapons[i]), sizeof(weapons[i]));
                }
                saveSystem.close();
                return true;
            }
            else
            {
                cout << "���������� �� �������" << endl;
                return false;
            }
        }
    };
    Warrior Load()
    {
        ifstream loadSystem("save.bin", ios::binary);
        Warrior warrior; //��������� ��������� ��� ���������� ������ �� �����
        warrior = Npc::Load();
        if (loadSystem.is_open())
        {
            loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));
            for (int i = 0; i < 4; i++)
            {
                loadSystem.read(reinterpret_cast<char*>(&weapons[i]), sizeof(weapons[i]));
            }
        }
        else
        {
            cout << "����� � ����� ��������\n������ �������" << endl;
            return warrior;
        }
        loadSystem.close();
        return warrior;


    };


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
    void GetInfo() override  //����������� (���������� ��� ������)
    {
        Npc::GetInfo();
        cout << "���� - " << strenght << endl;
        cout << "��������� ������ - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << weapons[i] << endl;
        }
    }
    unsigned int GetStrenght()
    {
        return strenght;
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
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }

    //���������� - �����, ������� ���������� ������������� ��� ������������� ������
    //��� ��������� ������ � ����������� ������ (������ ������� �������)
    ~Warrior() //���������� ������ ��� ����������
    {
        cout << name << " ��� ������� �������" << endl;
    }
};


//virtual - ������� ������������� �������, �������
//��� ���� ��� ����� �������� �� ���������
class Wizard : public virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "�������", "����������� ������", "�������� ���", "����������� �����" };
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
    void GetInfo() override  //����������� (���������� ��� ������)
    {
        Npc::GetInfo();
        cout << "��������� - " << intellect << endl;
        cout << "��������� ���������� � ����� ���������� - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    unsigned int GetIntellect()
    {
        return intellect;
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
    bool operator == (const Wizard& wizard) const
    {
        return ((wizard.damage == this->damage) && (wizard.health == this->health)
            && (wizard.intellect == this->intellect));
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
    bool Save() override
    {


        if (Npc::Save())
        {
            ofstream saveSystem("save.bin", ios::binary);
            if (saveSystem.is_open())
            {

                saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
                for (int i = 0; i < 4; i++)
                {
                    saveSystem.write(reinterpret_cast<const char*>(&spell[i]), sizeof(spell[i]));
                }
                saveSystem.close();
                return true;
            }
            else
            {
                cout << "���������� �� �������" << endl;
                return false;
            }
        }
    }
    ~Wizard() //���������� ������ ��� ����������
    {
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
        cout << "��������� ���������� � ����� ���������� - ";
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
    bool operator == (const Paladin& paladin) const
    {
        return ((paladin.damage == this->damage) && (paladin.health == this->health)
            && (paladin.intellect == this->intellect)) && (paladin.strenght == this->strenght);
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
  
    }
    /*void operator = (Warrior& warrior) override
    {
        this->name = warrior.GetStrenght();
        //this->name = warrior.GetIntellect();
    }*/
    bool Save() override
    {


        if (Npc::Save())
        {
            ofstream saveSystem("save.bin", ios::binary);
            if (saveSystem.is_open())
            {

                saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
                for (int i = 0; i < 4; i++)
                {
                    saveSystem.write(reinterpret_cast<const char*>(&spell[i]), sizeof(spell[i]));
                }
                saveSystem.close();
                return true;
            }
            else
            {
                cout << "���������� �� �������" << endl;
                return false;
            }
        }
    }
};



