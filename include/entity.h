#ifndef entity_h
#define entity_h

#include <string>

// Represents any entity that appears on the map.
class Entity {
	protected:
		int x;
		int y;
		char symbol;
		std::string name;
	public:
		void print();
};

#endif
