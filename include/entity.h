#ifndef character_h
#define character_h

#include "../include/common.h"

// Represent an entity that can move around the map
class Entity {
	protected:
		char symbol;
		int health;

	public:
		Position pos;
		unsigned int damage;

		void print();
		virtual void move(int c) = 0;
		Entity(char sym, int hp, int ap);

		int operator - (Entity const &obj) {
			health -= obj.damage;
			return health;
		}
};

#endif
