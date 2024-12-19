#pragma once

#include "Item_A.h"

class Sword : public Item_A{
    int damage;
public:
    Sword(string name, int damage, float mass = 0.0f);
    virtual void use() override;
};