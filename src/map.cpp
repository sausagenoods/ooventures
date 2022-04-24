#include <iostream>
#include <fstream>

#include <ncurses.h>

#include "../include/map.h"

void Map::print() {
	// Print the map
	for (int y = 0; y < LINES; y++)
		for (int x = 0; x < COLS; x++)
			mvaddch(y, x, '.');

	box(stdscr, 0, 0);
	refresh();
}

Map::Map()
{
	// Initialize ncurses
	initscr();
	// Don't echo key presses
	noecho();
	// Hide cursor
	curs_set(0);

	print();
}

Map::~Map()
{
	endwin();
}
