#ifndef __BOARD_H_
#define __BOARD_H_

// #include "item.h"
#include "sdl_utils.h"
#include "defs.h"

#include <stdbool.h>


typedef struct game_s game_t;


typedef struct cell_s
{
	tile_t* tile;
	
	bool is_wall;
	bool is_border;

    // ITEM INSIDE CELL
	// E_ITEM item;

} cell_t;


typedef struct board_s
{
	SDL_Texture* tileset;
	
	int width, height;

	cell_t* cells;
}board_t; 


cell_t* create_cell(game_t* game);
board_t* create_board();

void init_cell(cell_t* cell);
void init_board(board_t* board, game_t* game);

void destroy_board(board_t* board);

void board_to_screen(vector2_t* vect, int x, int y);
void screen_to_board(vector2_t* vect, float x, float y);


#endif
