#include <ncurses.h>

#include "../include/game.h"

Game::Game()
{
	// For randomness of spawns
	srand(time(NULL));
	map = new Map();
	player = new Player('@', 100, 3);
	for (int i = 0; i < MAX_MONSTER_SPAWN_COUNT; i++) {
		Monster m('$', 5, 5);
		monsters.push_back(m);
	}

	// Enable colors
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);

	mvprintw(0, 0, "Press any key to start.");
}

int Game::nextTurn(int c)
{
	print();
	if (c == 'h') {
		mvprintw(0, 0, "Key bindings:     ");
		mvprintw(1, 0, "  - w: Move up.   ");
		mvprintw(2, 0, "  - a: Move right.");
		mvprintw(3, 0, "  - s: Move down. ");
		mvprintw(4, 0, "  - d: Move left. ");
		mvprintw(5, 0, "  - q: Quit.      ");
		return 0;
	}
	if (c != 'w' && c != 'a' && c != 's' && c != 'd') {
		mvprintw(0, 0, "Invalid keypress. Press 'h' for help.");
		return 0;
	}

	// Check if there are any monsters next to the player
	// If there are return their position
	Position monsterPos = player->aroundMonster();

	int playerHp, monsterHp;
	bool inFight = false;
	std::vector<Monster>::iterator nearbyMonsterIter;
	Monster *nearbyMonster;

	if (monsterPos.x != -1) {
		inFight = true;
		nearbyMonsterIter = getMonsterNearby(monsterPos);
		nearbyMonster = &(*nearbyMonsterIter);
	}

	// Initiate fight until someone dies
	while (inFight) {
		playerHp = *player - *nearbyMonster;
		monsterHp = *nearbyMonster - *player;
		if (playerHp <= 0) {
			mvprintw(0, 0, "You have been slain.");
			return 0;
		} else if (monsterHp <= 0) {
			mvprintw(0, 0, "The monster has been slain.");
			monsters.erase(nearbyMonsterIter);
			inFight = false;
		} else {
			mvprintw(0, 0, "Player: %d HP\tMonster: %d HP", playerHp,
				monsterHp);
		}
		return 0;
	}

	player->move(c);

	for (auto i = monsters.begin(); i != monsters.end(); i++)
		i->move(c);

	return 0;
}

std::vector<Monster>::iterator Game::getMonsterNearby(Position mPos)
{
	for (auto i = monsters.begin(); i != monsters.end(); i++) {
		if (i->pos.y == mPos.y && i->pos.x == mPos.x)
			return i;
	}
}

void Game::print()
{
	attron(COLOR_PAIR(1));
	map->print();
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	player->print();
	attron(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	for (auto i = monsters.begin(); i != monsters.end(); i++)
		i->print();
	attroff(COLOR_PAIR(3));
}

Game::~Game()
{
	delete player;
	delete map;
}
