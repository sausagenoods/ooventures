#include <cstdlib>

#include "../include/monster.h"
#include "../include/common.h"

void Monster::move(int c)
{
	int move = (rand() % 6);
	switch (move) {
		case 0:
			if (checkBoundaries(pos.y - 1, pos.x))
				pos.y -= 1;
			break;
		case 1:
			if (checkBoundaries(pos.y, pos.x - 1))
				pos.x -= 1;
			break;
		case 2:
			if (checkBoundaries(pos.y + 1, pos.x))
				pos.y += 1;
			break;
		case 3:
			if (checkBoundaries(pos.y, pos.x + 1))
				pos.x += 1;
			break;
		case 4:
			// Once in a while stay still
			break;
		case 5:
			// Once in a while run away from the player
			moveWASD(&pos, c);
			break;
	}
}
