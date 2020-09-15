#include "item.h"
#include "game.h"


void init_item(game_t* game, item_t* item, E_ITEM item_type, int score)
{
    item->item_type = item_type;
    item->score = score;

    item->tile = malloc(sizeof(tile_t));


    SDL_Surface* surface;

    switch(item_type)
    {
        case E_PILL:
            item->tile->row = 0;
            item->tile->column = 0;
            item->tile->width = 8;
            item->tile->height = 8;

            surface = IMG_Load("assets/pac man pill/spr_pill_0.png");
            if (surface == NULL)
                return;
            
            item->sprite = utils_load_texture(game->draw->renderer, surface);

            SDL_FreeSurface(surface);
            break;
        case E_BIG_PILL:
            item->tile->row = 0;
            item->tile->column = 0;
            item->tile->width = 16;
            item->tile->height = 16;

            surface = IMG_Load("assets/pac man pill/spr_power_pill_0.png");
            if (surface == NULL)
                return;
            
            item->sprite = utils_load_texture(game->draw->renderer, surface);

            SDL_FreeSurface(surface);
            break;
        default:;
    }
}

void destroy_item(item_t* item)
{
    free(item->tile);
    SDL_DestroyTexture(item->sprite);
    free(item);
}