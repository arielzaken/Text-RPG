#include "pch.h"
#include "Grid.h"
#include "Tile.h"
#include "Wall.h"
#include "Entity_A.h"
#include "World.h"

TEST(Grid, int) {
	Grid<uint8_t> grid(10, 20);
	ASSERT_EQ(grid.getHeight(), 20);
	ASSERT_EQ(grid.getWidth(), 10);
	grid.at(1, 1) = 8;
	ASSERT_EQ(grid.at(1, 1), 8);
	ASSERT_ANY_THROW(grid.at(0, 25));
	ASSERT_ANY_THROW(grid.at(70, 0));
	ASSERT_ANY_THROW(grid.at(25, 35));
	ASSERT_EQ(grid.at(1, 1), 8);
	grid.at(1, 1) = 10;
	ASSERT_EQ(grid.at(1, 1), 10);
}

TEST(Grid, Tile) {
	Grid<Tile> grid(2, 2);
	Wall(grid.at(1, 1), 77);
	Wall(grid.at(0, 0), 33);
	ASSERT_EQ(grid.getHeight(), 2);
	ASSERT_EQ(grid.getWidth(), 2);
}

TEST(Tile, Entity) {
	Tile tile; 
	Wall wall(tile);
	ASSERT_EQ(wall.getName(), "Wall");
	ASSERT_EQ(tile.getEntity(), &wall);
	ASSERT_EQ(tile.getHeight(), 20);
	Wall wall2(tile, 15);
	ASSERT_EQ(wall.getName(), "Wall");
	ASSERT_EQ(tile.getEntity(), &wall2);
	ASSERT_EQ(tile.getHeight(), 35);
}

TEST(World, Entity) {
	{
		World world(3, 3);
		world.print();
	}
	printf("sup"); // for chacking if the distructor is working properly
}