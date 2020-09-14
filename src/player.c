#include "player.h"

#include "game.h"



#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>


player_t* create_player()
{
    player_t* player = malloc(sizeof(player_t));

	board_to_screen(player->pos, PLAYER_START_X, PLAYER_START_Y);
    board_to_screen(player->dest, PLAYER_START_X, PLAYER_START_Y);
    board_to_screen(player->newdest, PLAYER_START_X, PLAYER_START_Y);    
    
    player->speed = PLAYER_SPEED;

    player->dir = NONE;
    player->newdir = NONE;

	return player;
}

void destroy_player(player_t* player)
{
    free(player->pos);
    free(player->dest);
    free(player->newdest);
    free(player);
}


void player_process(game_t* game, float deltaTicks)
{
    board_t* board = game->board;
    input_t* input = game->input;
    player_t* player = game->player; 

    player_update_direction(board, input->dir, player);            

    if (player_check_destination(player))
    {
        float velocity = player->speed * deltaTicks;

        player_update_position(player, velocity);
    }
    
    if (!player_check_destination(player))
    {
        if (player->dir == player->newdir)
        {
            player->pos = player->dest;
            player_update_direction(board, player->dir, player);
        }
        
        player->dir = player->newdir;
        player->dest = player->newdest;
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
            return player->pos->y > player->dest->y;
        case DOWN:
            return player->pos->y < player->dest->y;
        case LEFT:
            return player->pos->x > player->dest->x;
        case RIGHT:
            return player->pos->x < player->dest->x;
        default:
            break;
    }
    return false;
}



void player_update_direction(board_t* board, E_DIR dir, player_t* player)
{
    if (player->dest == NULL)
        return;

    vector2_t* vect = malloc(sizeof(vector2_t));
    screen_to_board(vect, player->dest->x, player->dest->y);
    int x = vect->x;
    int y = vect->y;
    free(vect);

    //printf("x = %i & y = %i\n", x, y);

    switch(dir)
    {
        case UP:
            if (y > 0 && !board->cells[x + (y - 1) * board->width].is_wall)
            {                         
                player->newdir = UP;      
                board_to_screen(player->newdest, x, y - 1);
                return;
            }
            break;
        case DOWN:
            if (y < BOARD_HEIGHT - 1 && !board->cells[x + (y + 1) * board->width].is_wall)
            {
                player->newdir = DOWN;
                board_to_screen(player->newdest, x, y + 1);
                return;
            }
            break;
        case LEFT:
            if (x > 0 && !board->cells[x - 1 + y * board->width].is_wall)
            {
                player->newdir = LEFT;
                board_to_screen(player->newdest, x - 1, y);
                return;
            }
            break;
        case RIGHT:
            if (x < BOARD_WIDTH - 1 && !board->cells[x + 1 + y * board->width].is_wall)
            {
                player->newdir = RIGHT;
                board_to_screen(player->newdest, x + 1, y);
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
            player->pos->y -= velocity;
            player->pos->x = player->dest->x;
            break;
        case DOWN:
            player->pos->y += velocity;
            player->pos->x = player->dest->y;
            break;
        case LEFT:
            player->pos->x -= velocity;
            player->pos->y = player->dest->y;
            break;
        case RIGHT:
            player->pos->x += velocity;
            player->pos->y = player->dest->y;
            break;
        default:
            break;
    }
}
