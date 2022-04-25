#ifndef game_h
#define game_h

#include <vector>

#include "../include/map.h"
#include "../include/monster.h"
#include "../include/player.h"

#define MAX_MONSTER_SPAWN_COUNT 10

class Game {
	private:
		Player *player;
		Map *map;
		std::vector<Monster> monsters;

	public:
		int state;
		std::vector<Monster>::iterator getMonsterNearby(Position mPos);
		int nextTurn(int c);
		void print();
		Game(int difficulty);
		~Game();
};

#endif
