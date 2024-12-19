#pragma once

#include <stdint.h>
#include "Tile.h"
#include "Grid.h"
#include "Renderable.h"
#include <fmt/color.h>
using namespace std;

using TilePrintF_t = void (*) (const Tile*);

void printTile(const Tile*);

class World : public Renderable
{
private:
    Grid<Tile> next;
    Grid<Tile> old;
public:
    World() {}
    World(uint16_t x, uint16_t y);
    void draw(WINDOW* window) override;
};