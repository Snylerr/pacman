#ifndef __SDL_UTILS__
#define __SDL_UTILS__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>


typedef struct s_game t_game;

typedef struct
{
	int width, height;
	int row, column;
}tile_t;

void utils_init_window_and_renderer(SDL_Window** window, SDL_Renderer** renderer);

SDL_Texture* utils_load_texture(SDL_Renderer* renderer, SDL_Surface* surface);

void utils_entity_render_cpy(t_game* game, void* entity);

void utils_cell_render_cpy(t_game* game, board_t* board, cell_t* cell, int x, int y);

#endif
