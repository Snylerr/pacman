#ifndef __PLAYER__
#define __PLAYER__

typedef struct player_s
{
    int x;
    int y;

    float speed;

} player_t;


player_t create_player();
void destroy_player();

void move_player(game_t game);

void check_wall_collision(game_t game);



#endif
