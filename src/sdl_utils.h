#ifndef __SDL_UTILS__
#define __SDL_UTILS__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

typedef struct board_s board_t;

typedef struct cell_s cell_t;

typedef struct game_s game_t;

typedef struct
{
	int width, height;
	int row, column;
}tile_t;

void utils_init_window_and_renderer(SDL_Window** window, SDL_Renderer** renderer);

SDL_Texture* utils_load_texture(SDL_Renderer* renderer, SDL_Surface* surface);

void utils_entity_render_cpy(game_t* game, void* entity);

void utils_cell_render_cpy(game_t* game, board_t* board, cell_t* cell, int x, int y);

#endif
