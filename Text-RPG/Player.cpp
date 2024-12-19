#include "Player.h"

Vec2D<uint16_t> Player::moveLogic(const Grid<Tile>& world, Vec2D<uint16_t> pos) const
{
	int16_t myHeight = world.at(pos).getHeight();
	int16_t minHeight = myHeight;
	Vec2D<uint16_t> res = pos;
	world.forRegion((ForRegionCF_t<Tile>)[&](const Tile& element, uint16_t x, uint16_t y) 
	{
		int16_t thisHeight = element.getHeight();
		if (thisHeight < minHeight) {
			res = { x, y };
			minHeight = thisHeight;
		}
	}, pos[X], pos[Y], 1);
	return res;
}
