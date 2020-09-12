#include "player.h"

#include "game.h"


#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>


player_t* create_player()
{
    player_t* player = malloc(sizeof(player_t));

    player->x = PLAYER_START_X * UNIT_SIZE + OFFSET;
    player->y = PLAYER_START_Y * UNIT_SIZE + OFFSET;
	
	player->destX = player->x;
	player->destY = player->y;

    player->speed = PLAYER_SPEED;

    player->dir = NONE;

	return player;
}

void destroy_player(player_t* player)
{
    free(player);
}


float abs_(float x)
{
    if (x < 0)
        return -x;
    return x;
}

bool player_ready_to_move(player_t* player)
{
    return abs_(player->x - player->destX) < MARGE && abs_(player->y - player->destY) < MARGE;
} // ok mais il bouge plus la

void player_update_destination(game_t* game)
{
    if (game == NULL)
        return;

    board_t* board = game->board;
    input_t* input = game->input;
    player_t* player = game->player;

    int x = (player->x - OFFSET) / UNIT_SIZE;
    int y = (player->y - OFFSET) / UNIT_SIZE;

    if (input->dir == UP && y > 0 && !board->cells[x + (y - 1) * board->width].is_wall)
    {
        player->dir = UP;
    }
    else if (input->dir == DOWN && y < BOARD_HEIGHT - 1 && !board->cells[x + (y + 1) * board->width].is_wall)
    {
        player->dir = DOWN;
    }
    else if (input->dir == LEFT && x > 0 && !board->cells[x - 1 + y * board->width].is_wall)
    {
        player->dir = LEFT;
    }
    else if (input->dir == RIGHT && x < BOARD_WIDTH - 1 && !board->cells[x + 1 + y * board->width].is_wall)
    {
        player->dir = RIGHT;
    } 


    if (player->dir == UP && player_ready_to_move(player))
    {
        printf("GO UP PLZ\n");
        player->destX = x       * UNIT_SIZE + OFFSET;
        player->destY = (y - 1) * UNIT_SIZE + OFFSET;
    }
    else if (player->dir == DOWN && player_ready_to_move(player))
    {
        printf("GO DOWN PLZ\n");
        player->destX = x       * UNIT_SIZE + OFFSET;
        player->destY = (y + 1) * UNIT_SIZE + OFFSET;
    }
    else if (player->dir == LEFT && player_ready_to_move(player))
    {
        printf("GO LEFT PLZ\n");
        player->destX = (x - 1) * UNIT_SIZE + OFFSET;
        player->destY = y       * UNIT_SIZE + OFFSET;
    }
    else if (player->dir == RIGHT && player_ready_to_move(player))
    {
        printf("GO RIGHT PLZ\n");
        player->destX = (x + 1) * UNIT_SIZE + OFFSET;
        player->destY = y       * UNIT_SIZE + OFFSET;
    }
}

void player_move(game_t* game, float deltaTicks)
{
    if (game == NULL)
        return;

    player_t* player = game->player;

    if (player->dir == NONE || player_ready_to_move(player))
    {
        player_update_destination(game);
    }

    float vel = player->speed * (deltaTicks / 1000.f);
    //printf("%f", vel);
    // ELSE WE MOVE FORWARD
    if (player->destX < player->x)
    {
        printf("going LEFT\n");
        player->x -= vel;
    }
    else if (player->destX > player->x)
    {
        printf("going RIGHT\n");
        player->x += vel;
    }
    else if (player->destY < player->y)
    {
        printf("going UP\n");
        player->y -= vel;
    }
    else if (player->destY > player->y)
    {
        printf("going DOWN\n");
        player->x += vel;
    }

    
    
}