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
    player->newdestX = player->x;
    player->newdestY = player->y;


    player->speed = PLAYER_SPEED;

    player->dir = NONE;
    player->newdir = NONE;

	return player;
}

void destroy_player(player_t* player)
{
    free(player);
}


void player_process(game_t* game, float deltaTicks)
{
    board_t* board = game->board;
    input_t* input = game->input;
    player_t* player = game->player;

    
     
    player_update_direction(board, input->dir, player);
    //if (player->destX == player->newdestX && player->destY == player->newdestY)
            

    if (player_check_destination(player))
    {
        float velocity = player->speed * deltaTicks;
        player_update_position(player, velocity);
    }
    else
    {
        if (player->dir == player->newdir)
            player_update_direction(board, player->dir, player);
        player->dir = player->newdir;
        player->destX = player->newdestX;
        player->destY = player->newdestY;
        
        //printf("POSX = %f && DESTX = %f \n", (player->x), (player->destX));
    }      
  
    


 
    // DEBUG
    //printf("POSX = %f && DESTX = %f \n", (player->x), (player->destX));
}

bool player_check_destination(player_t* player)
{
    if (player->dir == NONE)
        player->dir = player->newdir;


    switch(player->dir)
    {
        case UP:
            return player->y > player->destY;
        case DOWN:
            return player->y < player->destY;
        case LEFT:
            return player->x > player->destX;
        case RIGHT:
            return player->x < player->destX;
        default:
            break;

    }
    return false;
}



void player_update_direction(board_t* board, E_DIR dir, player_t* player)
{
    int x = (player->destX - OFFSET) / (int)UNIT_SIZE;
    int y = (player->destY - OFFSET) / (int)UNIT_SIZE;

    //printf("x = %i & y = %i\n", x, y);

    switch(dir)
    {
        case UP:
            if (y > 0 && !board->cells[x + (y - 1) * board->width].is_wall)
            {                         
                player->newdir = UP;
                player->newdestX = x * UNIT_SIZE + OFFSET;
                player->newdestY = (y - 1) * UNIT_SIZE + OFFSET;
                return;
            }
            break;
        case DOWN:
            if (y < BOARD_HEIGHT - 1 && !board->cells[x + (y + 1) * board->width].is_wall)
            {
                player->newdir = DOWN;
                player->newdestX = x * UNIT_SIZE + OFFSET;
                player->newdestY = (y + 1) * UNIT_SIZE + OFFSET;
                return;
            }
            break;
        case LEFT:
            if (x > 0 && !board->cells[x - 1 + y * board->width].is_wall)
            {
                player->newdir = LEFT;
                player->newdestX = (x - 1) * UNIT_SIZE + OFFSET;
                player->newdestY = y * UNIT_SIZE + OFFSET;
                return;
            }
            break;
        case RIGHT:
            if (x < BOARD_WIDTH - 1 && !board->cells[x + 1 + y * board->width].is_wall)
            {
                player->newdir = RIGHT;
                player->newdestX = (x + 1) * UNIT_SIZE + OFFSET;
                player->newdestY = y * UNIT_SIZE + OFFSET;
                return;
            }
            break;
        default:
            break;
    }
}


void player_update_position(player_t* player, float velocity)
{
    switch(player->dir)
    {
        case UP:
            player->y -= velocity;

            player->x = player->destX;
            break;
        case DOWN:
            player->y += velocity;
            player->x = player->destX;
            break;
        case LEFT:
            player->x -= velocity;
            player->y = player->destY;
            break;
        case RIGHT:
            player->x += velocity;
            player->y = player->destY;
            break;
        default:
            break;
    }
}
