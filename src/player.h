#ifndef __PLAYER__
#define __PLAYER__

typedef struct player_s
{
    int x;
    int y;

    int destX;
    int destY; 

    float speed;

} player_t;


player_t* create_player();
void destroy_player(player_t* player);


void player_update_destination(game_t* game);
void player_move(game_t* game);




#endif
