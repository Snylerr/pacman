#ifndef __PLAYER__
#define __PLAYER__

#include "defs.h"
#include "sdl_utils.h"

#include <stdbool.h>


typedef struct game_s game_t;
typedef struct board_s board_t;
typedef struct input_s input_t;


typedef struct player_s
{
	tile_t* tile;
	
	SDL_Texture* sprite;
	
    float x;
    float y;

    float destX;
    float destY; 
    float newdestX;
    float newdestY;
    
    E_DIR dir;
    E_DIR newdir;

    float speed;

} player_t;

// CREATION & DESTRUCTION
player_t* create_player();
void destroy_player(player_t* player);

// MAIN PLAYER UPDATE LOOP
void player_process(game_t* game, float deltaTicks);

// Dependencies
bool player_check_destination(player_t* player);
void player_update_direction(board_t* board, E_DIR dir, player_t* player);
void player_update_destination(player_t* player);
void player_update_position(player_t* player, float velocity);




#endif
