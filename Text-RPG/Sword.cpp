#include "Sword.h"
#include <iostream>

Sword::Sword(string _name, int _damage, float _mass) : Item_A(_name, _mass), damage(_damage) {}

void Sword::use()
{
    cout << "Using " << getName() << " for " << damage << " damage." << endl;
}
