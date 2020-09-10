#ifndef __INPUT__
#define __INPUT__

#include <SDL2/SDL.h>

#include <stdbool.h>

typedef struct input_s
{
    bool up;
    bool down;
    bool left;
    bool right;

    bool enter;
    bool escape;

    bool exit;
} input_t;

input_t* create_input();

void destroy_input(input_t* input);


void input_process(input_t* input);

void input_key_down(input_t* input, SDL_KeyboardEvent* event);

void set_input(input_t* input, int up, int down, int left, int right);

#endif
