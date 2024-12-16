#include "World/World.h"
#include "Primitives/Grid/Grid.h"
#include <stdio.h>

World::World(uint16_t x, uint16_t y) : space(x, y)
{
    for (uint16_t i = 0; i < space.getWidth(); i++)
        for (uint16_t j = 0; j < space.getHeight(); j++){
            if (i == 0 || j == 0 || i == space.getWidth()-1 || j == space.getHeight()-1)
            {
                space.at(i, j) = tile::WALL;
            }
            else
            {
                space.at(i, j) = tile::FLOOR;
            }
        }
            
            
}
void World::print() const
{
    for (uint16_t j = 0; j < space.getHeight(); j++){
        for (uint16_t i = 0; i < space.getWidth(); i++){
            switch(static_cast<Tile>(space.at(i, j)))
            {
                case tile::WALL:
                    printf(" #");
                    break;
                case tile::FLOOR:
                    printf(" @");
                    break;
                case tile::EMPTY:
                    printf("  ");
                    break;
                default:
                    printf(" ?");
                    break;
            }
        }
        printf("\n");
    }
}