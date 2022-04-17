CC=g++
CFLAGS=-lncurses
LDFLAGS=-Wall

SRCS = $(wildcard src/*.cpp)

all: ooventures

ooventures: $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRCS) -o $@

clean:
	rm -f ooventure
