#pragma once
#include <iostream>
#include <fstream>
#include "Main.cpp"

using namespace std;

class Npc
{
protected: //����������� 0 ���������� (���� ������ ������ ������ �������� � ����������)
    //�� ��� ��� �� ���� ������ � �������� ������ ���������

    string name{ "��������" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };

public:    //��������� ����������� ������ (������������ ����� ����� � ����� �����)
    string GetName()
    {
        return name;
    }
    unsigned int GetHealth()
    {
        return health;
    }
    float GetDamage()
    {
        return damage;
    }
    unsigned int GetLvl()
    {
        return lvl;
    }
    /*unsigned int GetIntellect()
    {
        return intellect;
    }
    unsigned int GetStrenght()
    {
        return strenght;
    }*/
    virtual void GetInfo() //����� ������
    {
        cout << "��� - " << name << endl;
        cout << "�������� - " << health << endl;
        cout << "���� - " << damage << endl;
    }

    virtual void Create() {};
    virtual bool Save()
    {

        ofstream saveSystem("save.bin", ios::binary);
        if (saveSystem.is_open())
        {
            saveSystem.write(reinterpret_cast<const char*>(&name), sizeof(name));
            saveSystem.write(reinterpret_cast<const char*>(&health), sizeof(health));
            saveSystem.write(reinterpret_cast<const char*>(&damage), sizeof(damage));
            saveSystem.write(reinterpret_cast<const char*>(&lvl), sizeof(lvl));
            saveSystem.close();
            return true;
        }
        else
        {
            cout << "���������� �� �������\n���������� �����\n";
            return false;
        }
        saveSystem.close();
    };
    Npc Load()
    {
        ifstream loadSystem("save.bin", ios::binary);
        Npc npc; //��������� ��������� ��� ���������� ������ �� �����
        if (loadSystem.is_open())
        {
            loadSystem.read(reinterpret_cast<char*>(&npc.name), sizeof(npc.name));
            loadSystem.read(reinterpret_cast<char*>(&npc.health), sizeof(npc.health));
            loadSystem.read(reinterpret_cast<char*>(&npc.damage), sizeof(npc.damage));
            loadSystem.read(reinterpret_cast<char*>(&npc.lvl), sizeof(npc.lvl));
        }
        else
        {
            cout << "����� � ����� ��������\n������ � ����� ������� ������������ ����������\n";
            return npc;
        }
        loadSystem.close();
        return npc;
    };

};
class Player
{
public:
    void Create(Npc* player)
    {
        player->Create();
    }
    void Save(Npc* player)
    {
        player->Save();
    }
    void Load(Npc* player)
    {
        player->Load();
    }
};
