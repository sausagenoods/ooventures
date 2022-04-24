#include <ncurses.h>

#include "../include/character.h"

Character::Character(char sym, int hp, int ap)
{
	y = rand() % (LINES - 2);
	x = rand() % (COLS - 2);
	symbol = sym;
	health = hp;
	damage = ap;

	print();
}
