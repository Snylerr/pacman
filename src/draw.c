#include "draw.h"
#include "defs.h"
#include "game.h"

const int unit_half = UNIT_SIZE / 2;


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
	
	for (int i = 0; i < board->height; ++i)
	{
		for (int j = 0; j < board->width; ++j)
		{
			if(board->cells[j + i * board->width].is_wall)
			{
				SDL_SetRenderDrawColor(game->draw->renderer, 255, 0, 0, 255);
				SDL_Rect rect = {j * UNIT_SIZE + OFFSET - unit_half, i * UNIT_SIZE + OFFSET- unit_half, UNIT_SIZE, UNIT_SIZE};
				SDL_RenderFillRect(game->draw->renderer, &rect);
				
				SDL_SetRenderDrawColor(game->draw->renderer, 0, 0, 0, 255);
				SDL_Rect rect_ = {j * UNIT_SIZE + OFFSET- unit_half, i * UNIT_SIZE + OFFSET- unit_half, UNIT_SIZE, UNIT_SIZE};
				SDL_RenderDrawRect(game->draw->renderer, &rect_);
			}
		}
	}
}

void draw_player(game_t* game)
{
	SDL_SetRenderDrawColor(game->draw->renderer, 255, 255, 0, 255);
	SDL_Rect rect = {game->player->pos->x - unit_half, game->player->pos->y - unit_half, UNIT_SIZE, UNIT_SIZE};
	SDL_RenderDrawRect(game->draw->renderer, &rect);
}
