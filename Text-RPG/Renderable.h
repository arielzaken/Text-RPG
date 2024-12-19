#pragma once

#include <curses.h>

class Renderable
{
public:
	virtual void draw(WINDOW* window) = 0;
};