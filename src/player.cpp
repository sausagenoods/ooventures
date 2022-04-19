#include "../include/player.h"

Player::Player(int xpos, int ypos, char sym, int hp, int ap)
{
	x = xpos;
	y = ypos;
	symbol = sym;
	health = hp;
	damage = ap;
}

void Player::move(int c)
{
	switch(c) {
		case 'w':
			y -= 1;
			break;
		case 'a':
			x -= 1;
			break;
		case 's':
			y += 1;
			break;
		case 'd':
			x += 1;
			break;
	}
}
