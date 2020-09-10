#ifndef __DRAW__
#define __DRAW__

typedef struct draw_s
{
    SDL_WINDOW window;
    SDL_RENDERER renderer;
} draw_t;


void draw_board(game_t game);
void draw_player(game_t game);
void draw_enemies(game_t game);


#endif
