#include "board.h"
#include "map.h"
#include "defs.h"
#include "game.h"

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
	
	SDL_Surface* surface = IMG_Load("assets/pac man tiles/background2.png");
	if (surface == NULL)
		return;
	
	board->tileset = utils_load_texture(game->draw->renderer, surface);
	
	board->cells = malloc(board->width * board->height * sizeof(cell_t));
	
	read_map_file("include/board.map", board);
}

void screen_to_board(vector2_t* vect, float x, float y)
{
    if (vect == NULL)
        return;
    vect->x = (x - OFFSET) / UNIT_SIZE;
    vect->y = (y - OFFSET) / UNIT_SIZE;
}

void board_to_screen(vector2_t* vect, int x, int y)
{
    if (vect == NULL)
        return;  
    vect->x = x * UNIT_SIZE + OFFSET;
    vect->y = y * UNIT_SIZE + OFFSET;
}
