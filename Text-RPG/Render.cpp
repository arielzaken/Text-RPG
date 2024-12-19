#include "Render.h"
#include <curses.h>
#include <thread>
#include <chrono>

Render::Render()
{
	initscr();              // Initialize the screen
	noecho();               // Disable echoing of typed characters
	curs_set(0);            // Hide the cursor
	// Make getch non-blocking
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);   // Enable special keys (e.g., arrow keys)
}

Render::~Render()
{
	for (auto i = renderList.begin(); i < renderList.end(); i++) {
		delwin(i->pWindow);
	}
	endwin();               // End curses mode
}

void Render::addRenderable(RenderableVector_t&& rend)
{
	renderList.push_back(rend);
}

void Render::step()
{
	for (auto i = renderList.begin(); i < renderList.end(); i++){
		i->pRenderable->draw(i->pWindow);
		wrefresh(i->pWindow);
	}
}
