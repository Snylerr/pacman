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
	E_U_L = 71,
	E_U_R = 72,
	E_D_L = 81,
	E_D_R = 82,
	E_U = 30,
	E_D = 57,
	E_L = 27,
	E_R = 60,
	C_U_L = 84,
	C_U_R = 83,
	C_D_L = 74,
	C_D_R = 73,

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
