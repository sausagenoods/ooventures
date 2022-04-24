#ifndef common_h
#define common_h

// In order to be consistent with the ncurses library,
// instead of the (x, y) order (y, x) will be used.
typedef struct {
	int y;
	int x;
} Position;

bool checkBoundaries(int y, int x);

#endif
