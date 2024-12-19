#pragma once

#include <stack>
#include "Tile_types.h"

#define MAX_HEIGHT 256

class Entity_A;

class Tile
{
    friend class Entity_A;
    std::stack<EntityStack_t> entityStack;
public:
    Entity_A* getEntity() const;
    int16_t getHeight() const;
    ~Tile();
};
