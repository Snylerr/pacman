#include "board.h"
#include "map.h"
#include "defs.h"

#include <stdlib.h>

board_t* create_board()
{
	board_t* board = malloc(sizeof(board_t));
	
	init_board(board);
	
	return board;
}

void destroy_board(board_t* board)
{
	free(board->cells);
	free(board);
}

void init_board(board_t* board)
{
	board->width = BOARD_WIDTH;
	board->height = BOARD_HEIGHT;
	
	board->cells = malloc(board->width * board->height * sizeof(cell_t));
	
	read_map_file("include/board.map", board);
}