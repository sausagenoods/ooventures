#ifndef player_h
#define player_h

#include "../include/entity.h"

class Player : public Entity {
	public:
		void move(int c);
		Position aroundMonster();
		using Entity::Entity;
};

#endif
