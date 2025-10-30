#include <iostream>
#include "windows.h"
#include "MainClass.h"
#include "BasicClasses.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Warrior* warrior = new Warrior();
    Warrior* warrior2 = new Warrior();
    cout << (*warrior == *warrior2) << endl;

    Wizard* wizard = new Wizard();
    Paladin* paladin = new Paladin();
    Player* player = new Player();

    cout << "������, ������\n������� � ������ � �������� � ����\n";
    cout << "�� ������� ���? (1 - ����� ��������, 2 - ���������)\n";
    unsigned short choise = 1;
    //������� ���������� ������� ��� �������� ������� ������
    cin >> choise;
    while (choise > 2 || choise < 1)
    {
        cout << "�������� �� ������, ������� �����\n";
        cin >> choise;
    }
    if (choise == 1)
    {
        cout << "�������� � ����� �������\n\t1 - ����\n\t2 - ���������\n\t3 - �������\n";

        // ��� ��� ����� ������� ���� �������� �������
        cin >> choise;
        while (choise > 3 || choise < 1)
        {
            cout << "������ ��� �� ���� � ����� �����\n�� ��� �� �� ���������\n";
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
            cout << " " << endl;
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

    cout << "������� ��������� ���?\n\t1 - ��������� ����\n\t2 - ����������\n";
    cin >> choise;
    if (choise == 1)
    {
        if (warrior != nullptr) player->Save(warrior);
        if (wizard != nullptr) player->Save(wizard);
        if (paladin != nullptr) player->Save(paladin);
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
