#include <ncurses.h>

#include "../include/game.h"

Game::Game()
{
	// For randomness of spawns
	srand(time(NULL));
	map = new Map();
	pl = new Player('@', 100, 100);
	for (int i = 0; i < MAX_MONSTER_SPAWN_COUNT; i++) {
		Monster m('$', 5, 20);
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

	pl->move(c);

	for (auto i = monsters.begin(); i != monsters.end(); i++)
		i->move(c);

	return 0;
}

void Game::print()
{
	attron(COLOR_PAIR(1));
	map->print();
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	pl->print();
	attron(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	for (auto i = monsters.begin(); i != monsters.end(); i++)
		i->print();
	attroff(COLOR_PAIR(3));
}

Game::~Game()
{
	delete pl;
	delete map;
}
