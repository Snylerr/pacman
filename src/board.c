#include "board.h"
#include "map.h"
#include "defs.h"

#include <stdlib.h>

board_t* create_board(game_t* game)
{
	board_t* board = malloc(sizeof(board_t));
	
	init_board(board, game);
	
	return board;
}

void destroy_board(board_t* board)
{
	free(board->cells);
	free(board);
}

void init_board(board_t* board, game_t* game)
{
	board->width = BOARD_WIDTH;
	board->height = BOARD_HEIGHT;
	
	board->tileset = SDL_CreateTexture(game->draw->renderer, );
	
	board->cells = malloc(board->width * board->height * sizeof(cell_t));
	
	read_map_file("include/board.map", board);
}

vector2int_t* screen_to_board(float x, float y)
{
    vector2int_t* vect = malloc(sizeof(vector2int_t));
    vect->x = (x - OFFSET) / UNIT_SIZE;
    vect->y = (y - OFFSET) / UNIT_SIZE;
    return vect;
}

vector2int_t* board_to_screen(int x, int y)
{
    vector2int_t* vect = malloc(sizeof(vector2int_t));
    vect->x = x * UNIT_SIZE + OFFSET;
    vect->y = y * UNIT_SIZE + OFFSET;
    return vect;
}
