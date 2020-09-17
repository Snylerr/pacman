#ifndef __BOARD_H_
#define __BOARD_H_

// #include "item.h"
#include "sdl_utils.h"
#include "defs.h"
#include "item.h"

#include <stdbool.h>


typedef struct game_s game_t;

// MAIN BOARD STRUCTS

typedef enum E_CELL_SPRITE
{
	E_DOWN_RIGHT = 0,
	E_DOWN_LEFT = 1,
	E_DOWN = 3,
	E_RIGHT = 10,
	E_LEFT = 11,
	E_UP_RIGHT = 12,
	E_UP = 13,
	E_UP_LEFT = 17,

	E_DEFAULT
} E_CELL_SPRITE;

typedef struct cell_s
{
	tile_t tile;
	
	bool is_wall;
	bool is_border;

    // ITEM INSIDE CELL
	item_t item;

} cell_t;


typedef struct board_s
{
	SDL_Texture* tileset;
	
	int width, height;

	cell_t* cells;
}board_t; 

// ======================
// CREATION & DESTRUCTION

cell_t* 		create_cell			(game_t* game);
board_t* 		create_board		();

void 			init_cell			(cell_t* cell);
void 			init_board			(board_t* board, game_t* game);

void 			destroy_board		(board_t* board);


// ======================
// Coordinates converters

int 			screen_to_board		(int x);
int 			board_to_screen		(int x);


// ======================
// Handling the board to draw correct sprites

unsigned int 	matrix_filter		(board_t* board, int x, int y);
E_CELL_SPRITE 	get_cell_sprite		(board_t* board, int x, int y);
void 			set_tile_cell_sprite(board_t* board);

#endif
