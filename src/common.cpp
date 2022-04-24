#include <ncurses.h>

#include "../include/common.h"

bool checkBoundaries(int y, int x)
{
	if ((mvinch(y, x) & A_CHARTEXT) == '.')
		return true;
	return false;
}
