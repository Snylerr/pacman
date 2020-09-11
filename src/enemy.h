#ifndef __ENEMY__
#define __ENEMY__

typedef struct
{
    int x;
    int y;

    float speed;
} enemy_t;


enemy_t* create_enemy_list();

#endif
