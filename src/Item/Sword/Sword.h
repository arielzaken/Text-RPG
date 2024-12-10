#pragma once

#include "Item/Item_A.h"

class Sword : public Item_A{

public:
    Sword(string name, int damage, float mass = 0.0f);
    virtual void use() override;
};