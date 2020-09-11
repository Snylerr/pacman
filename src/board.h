#ifndef __BOARD_H_
#define __BOARD_H_

// #include "item.h"
#include "sdl_utils.h"

#include <stdbool.h>


typedef struct game_s game_t;

typedef struct cell_s
{
	tile_t tile;
	
	bool is_wall;

    // ITEM INSIDE CELL
	// E_ITEM item;

} cell_t;

typedef struct board_s
{
	int width, height;

	cell_t* cells;
}board_t; 

cell_t* create_cell();

void init_cell(cell_t* cell);

void init_board(board_t* board);

board_t* create_board();

void destroy_board(board_t* board);


#endif
