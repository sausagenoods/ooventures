#ifndef monster_h
#define monster_h

#include "../include/character.h"

class Monster: public Character {
	private:
		bool fight;
	public:
		void move(int c);
		using Character::Character;
};

#endif
