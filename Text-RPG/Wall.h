#pragma once

#include "Entity_A.h"

class Wall : public Entity_A{
public:
    virtual string getShowCharecter() const override { return "@@"; };
    virtual void tick(const Grid<Tile>& env, Grid<Tile>& next, Vec2D<uint16_t> pos) override {};
    virtual Entity_A* clone() override { return new Wall(*this); }
    Wall(Tile& tile, uint8_t h = 20) : Entity_A(tile, h) {};
};