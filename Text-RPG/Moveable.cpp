#include "Moveable.h"

void Moveable_A::tick(const Grid<Tile>& env, Grid<Tile>& next, Vec2D<uint16_t> pos)
{
    move(&next.at(moveLogic(env, pos)));
}

bool Moveable_A::move(Tile* newTile)
{
    if (tile->getEntity() == this) {
        getEntityStack(newTile)->push({this, (int16_t)(newTile->getHeight() + height) });
        popEntityStack(tile);
        tile = newTile;
        return true;
    }
    return false;
}
