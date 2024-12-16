#pragma once

#include <stdint.h>
#include "World/World.h"

class World;

class Entity_A
{
    uint32_t hp;
    int32_t damage;
    Tile* pos;
public:
    Entity_A(uint32_t hp, int32_t damage) : hp(hp), damage(damage) {}
};
