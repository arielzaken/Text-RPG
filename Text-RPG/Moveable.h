#pragma once

#include "Entity_A.h"
#include "World.h"

class Moveable_A : public Entity_A {
public:
	virtual Vec2D<uint16_t> moveLogic(const Grid<Tile>& world, Vec2D<uint16_t> pos) const = 0;
	virtual void tick(const Grid<Tile>& env, Grid<Tile>& next, Vec2D<uint16_t> pos) override;
	bool move(Tile* newTile);
};