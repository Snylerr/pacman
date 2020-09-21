#include "item.h"
#include "game.h"


void init_item(game_t* game, item_t* item, E_ITEM item_type, int score)
{
    item->item_type = item_type;
    item->score = score;

    tile_t tile = {};

	item->tile = tile;

    SDL_Surface* surface;

    switch(item_type)
    {
        case E_PILL:
            item->tile.row = 0;
            item->tile.column = 0;
            item->tile.width = 8;
            item->tile.height = 8;

            surface = IMG_Load("assets/pac man pill/pill_animated.png");
            if (surface == NULL)
                return;
            
            item->sprite = utils_load_texture(game->draw->renderer, surface);

            SDL_FreeSurface(surface);
            break;
        case E_BIG_PILL:
            item->tile.row = 0;
            item->tile.column = 0;
            item->tile.width = 16;
            item->tile.height = 16;

            surface = IMG_Load("assets/pac man pill/power_pill_animated.png");
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
	item->score = 0;
	item->item_type = E_NONE;
	
    SDL_DestroyTexture(item->sprite);
}
