#ifndef __BOARD_H_
#define __BOARD_H_


typedef struct
{
	cell_t cells[BOARD_WIDTH][BOARD_HEIGHT];
}board_t; 

typedef struct
{
    bool is_wall;

    // ITEM INSIDE CELL

} cell_t;

#endif
