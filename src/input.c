#include "input.h"

#include <stdlib.h>

input_t* create_input()
{
    input_t* input = malloc(sizeof(input_t));
    input->up = 0;
    input->down = 0;
    input->left = 0;
    input->right = 0;

    input->enter = 0;
    input->escape = 0;

    input->exit = 0;

    return input;
}

void destroy_input(input_t* input)
{
    free(my_input);
}

void input_process(input_t* input)
{
    SDL_EVENT event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                my_input->exit = 1;
                break;
            case SDL_KEYDOWN:
                input_key_down(input, &event.key);
                break;
            default:
                break;
        }
    }
}

void input_key_down(input_t* input, SDL_KeyboardEvent* event)
{
    switch(event->keysym.scancode)
    {
        case SDL_SCANCODE_RETURN:
            input->enter = 1;
            break;
        case SDL_SCANCODE_ESCAPE:
            input->escape = 1;
            break;
        case SDL_SCANCODE_UP:
            set_input(input, 1, 0, 0, 0);
            break;
        case SDL_SCANCODE_DOWN:
            set_input(input, 0, 1, 0, 0);
            break;
        case SDL_SCANCODE_LEFT:
            set_input(input, 0, 0, 1, 0);
            break;
        case SDL_SCANCODE_RIGHT:
            set_input(input, 0, 0, 0, 1);
            break;
        default:
            break;
    }
}

void set_input(input_t* input, int up, int down, int left, int right)
{
    input->up = up;
    input->down = down;
    input->left = left;
    input->right = right;
}
