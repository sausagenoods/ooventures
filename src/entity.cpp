#include <ncurses.h>

#include "../include/entity.h"

void Entity::print()
{
	mvaddch(y, x, symbol);
}
