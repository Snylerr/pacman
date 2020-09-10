<<<<<<< HEAD

CFLAGS=-Wall -Wextra -g -fsanitize=address
CPPFLAGS=-MMD -Iinclude
LDFLAGS=
LDLIBS=-lm -lSDL2 -lSDL2_image

SRCS=$(wildcard src/*.c)
FILES=$(subst src/,,$(SRCS))
OBJS=$(addprefix obj/,$(FILES:.c=.o))

DEPS=$(OBJS:.o=.d)

.PHONY: all clean

all: bin/pacman

-include $(DEPS)

obj/%.o: src/%.c
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

bin/pacman: $(OBJS)
	gcc $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -f $(OBJS) $(DEPS) bin/pacman
=======
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


>>>>>>> 23f8091e2ad1b1829ae698b7cff025b07e9a7345
