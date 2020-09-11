#ifndef __DRAW__
#define __DRAW__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "board.h"

typedef struct game_s game_t;

typedef struct draw_s
{
    SDL_Window* window;
    SDL_Renderer* renderer;
} draw_t;


draw_t* create_draw();

void draw_board(game_t* game);
void draw_player(game_t* game);
void draw_enemies(game_t* game);


#endif
