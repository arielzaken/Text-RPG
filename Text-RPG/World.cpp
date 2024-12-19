#include "World.h"
#include "Grid.h"
#include "Wall.h"
#include <fmt/color.h>
#include <fmt/core.h>

using namespace fmt;

World::World(uint16_t x, uint16_t y) : next(x, y)
{
    for (uint16_t j = 0; j < next.getHeight(); j++)
        for (uint16_t i = 0; i < next.getWidth(); i++) {
            if(i == 0 || j == 0 || i == next.getHeight()-1 || j == next.getWidth() - 1)
                new Wall(next.at(i, j), 127); // wall
            else
                new Wall(next.at(i, j), 10); // floor
        }
    old = next;
}

void World::draw(WINDOW* window)
{
    for (uint16_t i = 0; i < old.getWidth(); i++) {
        for (uint16_t j = 0; j < old.getHeight(); j++) {
            Entity_A* e = old.at(i, j).getEntity();
            if (e) {
                next.at(i, j).getEntity()->tick(old, next, Vec2D<uint16_t>({ i, j }));
            }
        }
    }
    old = next;
    box(window ,0 ,0);
    next.forEach([window](Tile& element, uint16_t x, uint16_t y)
        {
            wmove(window,x, y);
            if (!element.getEntity()) {
                addstr("  ");
                return;
            }
            addstr(element.getEntity()->getShowCharecter().c_str());
        });
}