#ifndef __BOARD_H_
#define __BOARD_H_

#include "item.h"

typedef struct game_s game_t;

typedef struct
{
	int width, height;

	cell_t* cells;
}board_t; 

typedef struct
{
	tile_t tile;
	
	bool is_wall;

    // ITEM INSIDE CELL
	E_ITEM item;

} cell_t;

cell_t* create_cell();



board_t* create_board();

void destroy_board(board_t* board);

void init_board(board_t* board);

#endif
