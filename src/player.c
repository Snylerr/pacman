#include "player.h"
#include "defs.h"

#include <stdlib.h>



player_t* create_player()
{
    player_t* player = malloc(sizeof(player_t));

    player->x = PLAYER_START_X;
    player->y = PLAYER_START_Y;

    player->speed = PLAYER_SPEED;

    player->dir = -1;
}

void destroy_player(player_t* player)
{
    free(player);
}


void player_update_destination(game_t* game)
{
    if (game == NULL)
        return;

    board_t* board = game->board;
    input_t* input = game->input;
    player_t* player = game->player;

    int x = player->x / UNIT_SIZE;
    int y = player->y / UNIT_SIZE;

    if (input->up && y > 0 && !board->cells[x][y - 1].is_wall)
    {
        player->dir = 0;
    }
    else if (input->down && y < BOARD_HEIGHT - 1 && !board->cells[x][y + 1].is_wall)
    {
        player->dir = 1;
    }
    else if (input->left && x > 0 && !board->cells[x-1][y].is_wall)
    {
        player->dir = 2;
    }
    else if (input->right && x < BOARD_WIDTH - 1 && !board->cells[x+1][y].is_wall)
    {
        player->dir = 3;
    } 


    if (player->dir == 0)
    {
        player->destX = x * UNIT_SIZE;
        player->destY = (y - 1) * UNIT_SIZE;
    }
    else if (player->dir == 1)
    {
        player->destX = x * UNIT_SIZE;
        player->destY = (y + 1) * UNIT_SIZE;
    }
    else if (player->dir == 2)
    {
        player->destX = (x - 1) * UNIT_SIZE;
        player->destY = y * UNIT_SIZE;
    }
    else if (player->dir == 3)
    {
        player->destX = (x + 1) * UNIT_SIZE;
        player->destY = y * UNIT_SIZE;
    }
}

void player_move(game_t* game, Uint32 deltaTicks)
{
    if (game == NULL)
        return;

    board_t* board = game->board;
    input_t* input = game->input;
    player_t* player = game->player;

    // PLAYER IS ON DESTINATION
    //if (player->x == player->destX && player->y == player->destY)
    //{
        player_update_destination(game);
    //}

    float vel = player->speed * (deltaTicks / 1000f);

    // ELSE WE MOVE FORWARD
    if (player->destX < player->x)
        player->x -= vel;
    else
        player->x += vel;

    if (player->destY < player->y)
        player->y -= vel;
    else
        player->x += vel;
    
}
