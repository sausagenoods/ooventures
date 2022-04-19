#ifndef player_h
#define player_h

#include <string>
#include "../include/character.h"

class Player : public Character {
	private:
		std::string item;
		// Extra attack and health points from current item
		unsigned int item_hp;
		unsigned int item_ap;
	public:
		void move(int c);
		Player(int xpos, int ypos, char sym, int hp, int ap);
};

#endif
