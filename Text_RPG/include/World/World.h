#pragma once

#include <stdint.h>
#include "World/Tile/Tile.h"
#include "Primitives/Grid/Grid.h"
using namespace std;

class World
{
private:
    // 2D array to represent the game world with tiles and obstacles.
    Grid<Tile> space;
public:
    World(uint16_t x, uint16_t y);
    void print() const;
};