#include "../include/game.h"

#define MAX_MONSTER_SPAWN_COUNT 10
#define MAX_ITEM_SPAWN_COUNT 10

Game::Game()
{
	pl = new Player(10, 10, '@', 100, 100);
	map = new Map("asset/map.txt");
}

int Game::nextTurn(int c)
{
	map->print();
	pl->move(c);
	pl->print();
	return 0;
}

Game::~Game()
{
	delete pl;
	delete map;
}
