#include <ncurses.h>

#include "../include/game.h"

int main()
{
	Game curr;
	int ch, status = 0;

	// Main game loop
	while ((ch = getch()) != 'q') {
		status = curr.nextTurn(ch);
	}
	return 0;
}
