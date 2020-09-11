#include "draw.h"
#include "defs.h"
#include "game.h"


draw_t* create_draw()
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	utils_init_window_and_renderer(&window, &renderer);
	
	draw_t* draw = malloc(sizeof(draw_t));
	
	draw->window = window;
	draw->renderer = renderer;

	return draw;
}

void draw_board(game_t* game)
{
	board_t* board = game->board;
	
	SDL_SetRenderDrawColor(game->draw->renderer, 255, 0, 0, 255);
	SDL_RenderClear(game->draw->renderer);
	
	for (int i = 0; i < board->height; ++i)
	{
		for (int j = 0; j < board->width; ++j)
		{
			if(board->cells[j + i * board->width].is_wall)
			{
				SDL_Rect rect = {j * UNIT_SIZE, i * UNIT_SIZE, UNIT_SIZE, UNIT_SIZE};
				SDL_RenderDrawRect(game->draw->renderer, &rect);
			}
		}
	}
}