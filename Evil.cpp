#include "Evil.h"

using namespace std;

Evil::Evil(const std::string& name) {
    this->name = name;
    health = 10;
    damage = 5.0f;  
}
Evil::Evil(const std::string& name, unsigned int health) : Evil(name) {
    this->health = health;
}
Evil::Evil(const std::string& name, unsigned int health, float damage) : Evil(name, health) {
    this->damage = damage;  
}
void Evil::GetInfo() {
    cout << endl;
    cout << "на вас напал " << name << endl;
    if (health >= 0 && damage < 0) {
        cout << "Здоровье - " << health << endl;
    }
    if (health < 0 && damage >= 0) {
        cout << "урон - " << damage << endl;
    }
    if (health >= 0 && damage >= 0) {
        cout << "Здоровье - " << health << endl;
        cout << "урон - " << damage << endl;
    }
}
