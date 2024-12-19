#pragma once

#include "Moveable.h"

class Player : public Moveable_A
{
public:
    virtual string getShowCharecter() const override { return "<>"; };
    virtual Vec2D<uint16_t> moveLogic(const Grid<Tile>& world, Vec2D<uint16_t> pos) const override;
};