#ifndef __GAME__
#define __GAME__

typedef struct game_s
{
    input_t* input;
    player_t* player;
    
    enemy_t enemies[MAX_ENEMIES];

} game_t;

#endif
