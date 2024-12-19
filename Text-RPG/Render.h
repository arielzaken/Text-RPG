#pragma once

#include "Renderable.h"
#include <memory>
#include <vector>
#include <curses.h>

using namespace std;

typedef struct RenderableVector_t{
	Renderable* pRenderable;
	WINDOW* pWindow;
} RenderableVector_t;

class Render {
	std::vector<RenderableVector_t> renderList;
public:
	Render();
	~Render();
	void addRenderable(RenderableVector_t&& rend);
	void step();
};