#ifndef map_h
#define map_h

#include <string>

#define MAP_COLS 80
#define MAP_LINES 24

class Map {
	private:
		std::string levelLayout[MAP_LINES];
	public:
		void print();
		Map(std::string filename);
		~Map();
};

#endif
