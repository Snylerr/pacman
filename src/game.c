#include "game.h"

game_t* create_game()
{
    game_t* game = malloc(sizeof(game_t));
    game->draw = create_draw();
    game->board = create_board(game);
    game->input = create_input();
    game->player = create_player();

    game->enemies = create_enemy_list();

    game->current_score = 0;
    game->high_score = 0;
	
	return game;
}

void reset_game(game_t* game)
{
    game->current_score = 0;
    
    // destroy_enemy_list(game->enemies);
    
}

void destroy_game(game_t* game)
{
    free(game->draw);
    free(game->input);
    free(game->player);
    
    // destroy_enemy_list(game->enemies);

    free(game);
}


void game_main_loop(game_t* game)
{
	Uint64 frequency = SDL_GetPerformanceFrequency();
	Uint64 counter = 0;
    float delta = 0.f;


	SDL_SetRenderDrawColor(game->draw->renderer, 0, 0, 0, 255);

    bool running = true;
    
    while (running)
    {
		
        input_process(game->input);

		Uint64 current_counter = SDL_GetPerformanceCounter();
		delta = counter > 0 ? (current_counter - counter) / (float)frequency : 1.f / 60.f;
		counter = current_counter;
		
        // QUIT GAME INSTANTLY
        if (game->input->exit)
            break;
        
        // PAUSE GAME
        if (game->input->escape)
        {
            game->input->escape = false;
            while (!game->input->escape)
            {
                // PAUSE
            }
        }
		SDL_SetRenderDrawColor(game->draw->renderer, 0, 0, 0, 255);
		SDL_RenderClear(game->draw->renderer);
		
		draw_board(game);
		draw_player(game);
		// Move player
		
        player_process(game, delta);

		SDL_RenderPresent(game->draw->renderer);

        // Restart delta timer
        delta = 0.f;
    }
}
