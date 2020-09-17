#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "sdl_utils.h"
#include "game.h"
#include "player.h"
#include "board.h"
#include "defs.h"
#include "draw.h"
#include "item.h"

void utils_init_window_and_renderer(SDL_Window** window, SDL_Renderer** renderer)
{
	if (TTF_Init() != 0)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
		return;
	}
	if (SDL_Init(SDL_INIT_VIDEO != 0))
	{
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return;
	}

	*window = SDL_CreateWindow("pacman",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_OPENGL);
	if (*window == NULL)
	{
		printf("Error creating window: %s\n", SDL_GetError());
		return;
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (*renderer == NULL)
	{
		printf("Error creating renderer: %s\n", SDL_GetError());
		return;
	}
	

}

SDL_Texture* utils_load_texture(SDL_Renderer* renderer, SDL_Surface* surface)
{
	SDL_Texture* texture = SDL_CreateTextureFromSurface(
							renderer, surface);
	return texture;
}

void utils_entity_render_cpy(game_t* game, void* entity)
{
	player_t* entity_ = (player_t*)entity;
	tile_t entity_tile = entity_->tile;
	
	int x = entity_->x;
	int y = entity_->y;
	
	int dir = entity_->dir;
	
	int angle = 180 * dir / 2;
	
	SDL_Point center = {entity_tile.width / 2, entity_tile.height / 2};

	SDL_Rect src_rect = {0, 0, entity_tile.width, entity_tile.height};
	SDL_Rect dst_rect = {x - entity_tile.width/2, y - entity_tile.height/2, 32, 32};

	SDL_RenderCopyEx(game->draw->renderer, entity_->sprite, &src_rect, &dst_rect, angle, &center, SDL_FLIP_NONE);
}

void utils_item_render_cpy(game_t* game, item_t item, int x, int y)
{
	tile_t item_tile = item.tile;

	SDL_Rect src_rect = {0, 0, item_tile.width, item_tile.height};
	SDL_Rect dst_rect = {x - item_tile.width/2, y - item_tile.height/2, item_tile.width, item_tile.height};

	SDL_RenderCopy(game->draw->renderer, item.sprite, &src_rect, &dst_rect);
}

void utils_cell_render_cpy(game_t* game, board_t* board, cell_t cell, int x, int y)
{
	tile_t cell_tile = cell.tile;

	SDL_Rect src_rect = {cell_tile.column * cell_tile.width, cell_tile.row * cell_tile.height, cell_tile.width, cell_tile.height};
	SDL_Rect dst_rect = {x, y, UNIT_SIZE, UNIT_SIZE};

	SDL_RenderCopy(game->draw->renderer, board->tileset, &src_rect, &dst_rect);
}
