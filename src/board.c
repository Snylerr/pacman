#include "board.h"

board_t* create_board(game_t game)
{
	board_t* board = malloc(sizeof(board_t));
	
	init_board(board);
	
	return board_t;
}

void destroy_board(board_t* board)
{
	free(board);
}

void init_board(board_t* board)
{
	board->width = BOARD_WIDTH;
	board->height = BOARD_HEIGHT;
	
	board->cell_t = create_cell();
}