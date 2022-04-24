#include <cstdlib>

#include <ncurses.h>

#include "../include/entity.h"

Entity::Entity(char sym, int hp, int ap)
{
	pos.y = rand() % (LINES - 2);
	pos.x = rand() % (COLS - 2);
	symbol = sym;
	health = hp;
	damage = ap;

	print();
}

void Entity::print()
{
	mvaddch(pos.y, pos.x, symbol);
}
