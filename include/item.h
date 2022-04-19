#ifndef item_h
#define item_h

#include "../include/entity.h"

// Represents items that can be picked up by the player
class Item : public Entity {
	public:
		unsigned int damageScore;
		unsigned int healthScore;
		Item();
};

#endif
