#include <iostream>
#include <fstream>

#include <ncurses.h>

#include "../include/map.h"

Map::Map(std::string filename)
{
	std::ifstream level;

	level.open(filename);
	if (!level.is_open()) {
		std::cout << "Error loading map." << std::endl;
		std::exit(1);
	}

	for (int i = 0; i < MAP_LINES; i++)
		getline(level, levelLayout[i]);

	level.close();

	// Initialize ncurses
	initscr();
	if (LINES < MAP_LINES || COLS < MAP_COLS) {
		endwin();
		std::cout << "Terminal too small." << std::endl;
		std::exit(2);
	}

	// Don't echo key presses
	noecho();

	// Print the map
	for (int i = 0; i < 24; i++) {
		printw(levelLayout[i].c_str());
		addch('\n');
	}
	refresh();
}

Map::~Map()
{
	endwin();
}