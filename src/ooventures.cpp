#include <iostream>
#include <sstream>
#include <string>

#include <ncurses.h>

#include "../include/game.h"

void printCentered(int yPos, std::string msg) {
	mvprintw(yPos, COLS / 2 - (msg.length() / 2), msg.c_str());
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: ./ooventures [difficulty level 1 to 3]"
			<< std::endl;
		return 1;
	}

	std::istringstream ss(argv[1]);
	int difficulty;
	if (!(ss >> difficulty)) {
		std::cout << "Difficulty level must be an integer" << std::endl;
		return 1;
	}

	if (!(difficulty > 0 && difficulty < 4)) {
		std::cout << "Difficulty levels are: 1 (easy), 2 (medium), 3 (hardcore)"
			<< std::endl;
		return 1;
	}

	Game curr(difficulty);
	int ch, status = 0;

	// Main game loop
	while ((ch = getch()) != 'q' && !status) {
		status = curr.nextTurn(ch);
	}
	if (status == 1) {
		printCentered(LINES / 2, "You have been slain!");
		printCentered(LINES / 2 + 1, "Press any key to quit.");
		getch();
	} else if (status == 2) {
		printCentered(LINES / 2, "You won!");
		printCentered(LINES / 2 + 1, "Press any key to quit.");
		getch();
	}
	return 0;
}
