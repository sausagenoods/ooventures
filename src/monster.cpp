#include "../include/monster.h"
#include "../include/common.h"

void Monster::move(int c)
{
	int move = (rand() % 5);
	switch (move) {
		case 0:
			if (checkBoundaries(y - 1, x))
				y -= 1;
			break;
		case 1:
			if (checkBoundaries(y, x - 1))
				x -= 1;
			break;
		case 2:
			if (checkBoundaries(y + 1, x))
				y += 1;
			break;
		case 3:
			if (checkBoundaries(y, x + 1))
				x += 1;
			break;
		case 4:
			// Once in a while stay still
			break;
	}
}
