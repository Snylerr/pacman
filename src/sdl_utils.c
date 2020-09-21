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


void utils_init_window_and_renderer(game_t* game, SDL_Window** window, SDL_Renderer** renderer)
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
	if (SDL_VideoInit(NULL) != 0) {
        printf("Error initializing SDL video:  %s\n", SDL_GetError());
        return;
    }

    SDL_DisplayMode dm;

	if (SDL_GetCurrentDisplayMode(0, &dm) != 0)
	{
	     SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
	     return;
	}

	game->screen_width = dm.w;
	game->screen_height = dm.h;
	game->mid_ref_width = (dm.w / 2 - BOARD_WIDTH * UNIT_SIZE * 1.5f) + OFFSET;
	game->mid_ref_height = (dm.h / 2 - BOARD_HEIGHT * UNIT_SIZE) + OFFSET;


	*window = SDL_CreateWindow("pacman",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			game->screen_width, game->screen_height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
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
	SDL_Rect dst_rect = {x - entity_tile.width/2 + game->mid_ref_width, y - entity_tile.height/2 + game->mid_ref_height, 32, 32};

	SDL_RenderCopyEx(game->draw->renderer, entity_->sprite, &src_rect, &dst_rect, angle, &center, SDL_FLIP_NONE);
}

void utils_item_render_cpy(game_t* game, item_t item, int x, int y, Uint32 item_sprite_state)
{
	if (item.item_type == E_WARP)
		return;
	tile_t item_tile = item.tile;

	int sprite_nb = 1;
	switch(item.item_type)
	{
		case E_PILL:
			sprite_nb = 6;
			break;
		case E_BIG_PILL:
			sprite_nb = 4;
			break;
		default :
			return;
	}



	SDL_Rect src_rect = {item_tile.width * (item_sprite_state % sprite_nb), 0, item_tile.width, item_tile.height};
	SDL_Rect dst_rect = {x - item_tile.width/2 + game->mid_ref_width, y - item_tile.height/2 + game->mid_ref_height, item_tile.width, item_tile.height};


	SDL_RenderSetScale(game->draw->renderer, 2, 2);
	SDL_RenderCopy(game->draw->renderer, item.sprite, &src_rect, &dst_rect);
}

void utils_cell_render_cpy(game_t* game, board_t* board, cell_t cell, int x, int y)
{

	if (cell.index == E_DEFAULT)
		return;
	tile_t cell_tile = cell.tile;

	SDL_Rect src_rect = {cell_tile.column * cell_tile.width, cell_tile.row * cell_tile.height, cell_tile.width, cell_tile.height};
	SDL_Rect dst_rect = {x - cell_tile.width/2 + game->mid_ref_width, y - cell_tile.height/2 + game->mid_ref_height, UNIT_SIZE, UNIT_SIZE};

	SDL_RenderCopy(game->draw->renderer, board->tileset, &src_rect, &dst_rect);
}
