#include <ncurses.h>

#include "../include/common.h"

// Make sure entities stay within boundaries
bool checkBoundaries(int y, int x)
{
	if ((mvinch(y, x) & A_CHARTEXT) == '.')
		return true;
	return false;
}

// Movement using W, A, S, D keys
void moveWASD(Position *pos, int c)
{
	switch(c) {
		case 'w':
			if (checkBoundaries(pos->y - 1, pos->x))
				pos->y -= 1;
			break;
		case 'a':
			if (checkBoundaries(pos->y, pos->x - 1))
				pos->x -= 1;
			break;
		case 's':
			if (checkBoundaries(pos->y + 1, pos->x))
				pos->y += 1;
			break;
		case 'd':
			if (checkBoundaries(pos->y, pos->x + 1))
				pos->x += 1;
			break;
	}
}
