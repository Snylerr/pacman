#ifndef __BOARD_H_
#define __BOARD_H_

#include "item.h"

typedef struct
{
	cell_t cells[BOARD_WIDTH][BOARD_HEIGHT];
}board_t; 

typedef struct
{
	tile_t tile;
	
	int x, y;
	
    bool is_wall;

    // ITEM INSIDE CELL
	E_ITEM item;

} cell_t;

#endif
