CC = gcc
CFLAGS = -W -Wall -Werror -Wextra -03
CPPFLAGS = -MMD -Iinclude
LDLIBS = -lm -lSDL2 -lSDL2_image -lSDL2_ttf

OBJS = $(patsubst %.c,%.o,$(wildcard src/*.c))

DEPS = $(OBJS:.o=.d)

.PHONY: all clean

all: pacman

-include $(DEPS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

pacman: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o pacman

clean:
	rm -f $(OBJS) $(DEPS) pacman


