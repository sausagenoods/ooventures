#ifndef monster_h
#define monster_h

#include "../include/entity.h"

class Monster: public Entity {
	public:
		void move(int c);
		using Entity::Entity;
};

#endif
