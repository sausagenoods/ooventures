#include <ncurses.h>

#include "../include/player.h"
#include "../include/common.h"

void Player::move(int c)
{
	switch(c) {
		case 'w':
			if (checkBoundaries(pos.y - 1, pos.x))
				pos.y -= 1;
			break;
		case 'a':
			if (checkBoundaries(pos.y, pos.x - 1))
				pos.x -= 1;
			break;
		case 's':
			if (checkBoundaries(pos.y + 1, pos.x))
				pos.y += 1;
			break;
		case 'd':
			if (checkBoundaries(pos.y, pos.x + 1))
				pos.x += 1;
			break;
	}
}

#define cAround(y, x) (mvinch(y,x) & A_CHARTEXT)

Position Player::aroundMonster()
{
	Position temp;

	// Impossible location default
	temp.x = -1;

	if (cAround(pos.y + 1, pos.x) == '$') {
		temp.y = pos.y + 1;
		temp.x = pos.x;
	} else if (cAround(pos.y, pos.x + 1) == '$') {
		temp.y = pos.y;
		temp.x = pos.x + 1;
	} else if (cAround(pos.y - 1, pos.x) == '$') {
		temp.y = pos.y - 1;
		temp.x = pos.x;
	} else if (cAround(pos.y, pos.x - 1) == '$') {
		temp.y = pos.y;
		temp.x = pos.x - 1;
	}
	return temp;
}
