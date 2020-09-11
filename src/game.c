#include "game.h"

game_t* create_game()
{
    game_t* game = malloc(sizeof(game_t));
    game->draw = create_draw();
    game->board = create_board();
    game->input = create_input();
    game->player = create_player();

    game->enemies = create_enemy_list();

    game->current_score = 0;
    game->high_score = 0;
}

void reset_game(game_t* game)
{
    game->current_score = 0;
    
    destroy_enemy_list(game->enemies);
    
}

void destroy_game(game_t* game)
{
    free(game->draw);
    free(game->input);
    free(game->player);
    
    destroy_enemy_list(game->enemies);

    free(game);
}


void game_main_loop(game_t* game)
{
    Timer delta;
    delta.start();


    bool running = true;
    
    while (running)
    {
        input_process(game->input);
        
        // QUIT GAME INSTANTLY
        if (input->exit)
            break;
        
        // PAUSE GAME
        if (input->escape)
        {
        
        }

        // Move player
        player_update_destionation(game);
        player_move(game, delta.get_ticks());


        // Restart delta timer
        delta.start();
    }
}
