#pragma once

#include "World/Tile/Tile_types.h"
#include "Entity/Entity_A.h"
#include <memory>
class Tile
{
private:
    tile::TileType type;
public:
    Tile() : type(tile::EMPTY) {}
    Tile(tile::TileType t) : type(t) {}
    tile::TileType getType() const { return type; }
    
    operator tile::TileType() { return type; }
};
