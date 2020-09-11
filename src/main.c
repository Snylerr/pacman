#include "game.h"

int main()
{
    game_t* game = create_game();
    
    game_main_loop(game);

    return 0;
}
