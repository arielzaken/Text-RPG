#pragma once

#include <stdint.h>
#include <string>
#include <fmt/color.h>
#include <fmt/core.h>
#include <math.h>
#include "Tile.h"
#include "Grid.h"
#include "Primitives.h"

using namespace std;

class Entity_A
{
protected:
    Tile* tile;
    uint8_t height;

    auto getEntityStack(Tile* _tile) { return &(_tile->entityStack); }
    void popEntityStack(Tile* _tile) { _tile->entityStack.pop(); }

public:
    virtual string getShowCharecter() const = 0;
    virtual void tick(const Grid<Tile>& env, Grid<Tile>& next, Vec2D<uint16_t> pos) = 0;
    //virtual fmt::text_style getColor() const = 0;

    // Constructor
    Entity_A(Tile& _tile, uint8_t h = 0) : tile(&_tile), height(h) {}
    Entity_A(const Entity_A& other) : tile(other.tile), height(other.height) {}

    virtual Entity_A* clone() = 0;

    // Getters and setters for height
    int8_t getHeight() { return height; }
    int8_t getHeight() const { return height; }
    void setHeight(int8_t h) { height = h; }

    // Getters for tile
    Tile* getTile() { return tile; }

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Entity_A() {}
};
