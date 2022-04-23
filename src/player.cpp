#include "../include/player.h"
#include "../include/common.h"

void Player::move(int c)
{
	switch(c) {
		case 'w':
			if (checkBoundaries(y - 1, x))
				y -= 1;
			break;
		case 'a':
			if (checkBoundaries(y, x - 1))
				x -= 1;
			break;
		case 's':
			if (checkBoundaries(y + 1, x))
				y += 1;
			break;
		case 'd':
			if (checkBoundaries(y, x + 1))
				x += 1;
			break;
	}
}
