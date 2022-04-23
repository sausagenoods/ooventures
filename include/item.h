#ifndef item_h
#define item_h

#include <map>

#include "../include/entity.h"

// Represents items that can be picked up by the player
class Item : public Entity {
	public:
		unsigned int damageScore;
		Item(char ch, int xpos, int ypos);
};

extern std::map<char, int> itemList;

#endif
