#ifndef __PLAYER__
#define __PLAYER__

#include "defs.h"

typedef struct game_s game_t;



typedef struct player_s
{
    float x;
    float y;

    float destX;
    float destY; 

    E_DIR dir;

    float speed;

} player_t;


player_t* create_player();
void destroy_player(player_t* player);


void player_update_destination(game_t* game);
void player_move(game_t* game, float deltaTicks);




#endif
