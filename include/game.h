#ifndef game_h
#define game_h

#include <vector>

#include "../include/item.h"
#include "../include/map.h"
#include "../include/monster.h"
#include "../include/player.h"

class Game {
	private:
		Player *pl;
		Map *map;
		//std::vector<Monster> monsters;
		//std::vector<Item> items;
	public:
		int state;
		int nextTurn(int c);
		Game();
		~Game();
};

#endif
