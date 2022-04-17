#include <ncurses.h>

#include "../include/map.h"

int main()
{
	Map currLevel("./asset/map/level0.txt");

	// Main game loop
	int ch;
	while ((ch = getch()) != 'q') {
		;
	}

	return 0;
}
