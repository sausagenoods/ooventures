#ifndef character_h
#define character_h

#include "../include/entity.h"

// Represent an entity that can move around the map and deal damage
class Character : public Entity {
	protected:
		unsigned int health;
		unsigned int damage;
		bool hostile;
	public:
		virtual void move(int c) = 0;
		Character(char sym, int hp, int ap);
};

#endif
