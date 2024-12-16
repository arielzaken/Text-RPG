#pragma once

#include "../Inventory/Inventory.h"

class Character_A
{
    int hp;
    int damage;
    unsigned int level;
public:
    Character_A(int hp, int damage, unsigned int level) : hp(hp), damage(damage), level(level) {}
};
