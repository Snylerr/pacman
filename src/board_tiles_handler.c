#include "board.h"

unsigned int matrix_filter(board_t* board, int x, int y)
{
    unsigned int res = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
                continue;

            if ((x + j < 0 && x + j > board->height && y + i < 0 && y + i > board->width)
                || board->cells[x + j + (y + i) * board->width].is_wall)
            {
                res += 1;
            }
            res <<= 1;
            printf("res: %i\n", res);
            
        }
    }
    return res;
}

E_CELL_SPRITE get_cell_sprite(board_t* board, int x, int y)
{
    int r = matrix_filter(board, x, y);
    printf("r: %i\n", r);
    switch(r)
    {
        case 248:
            return E_UP;
        case 31:
            return E_DOWN;
        case 214:
            return E_LEFT;
        case 107:
            return E_RIGHT;
        case 208:
            return E_UP_LEFT;
        case 112:
            return E_UP_RIGHT;
        case 22:
            return E_DOWN_LEFT;
        case 11:
            return E_DOWN_RIGHT;
        default:
            return E_DEFAULT;
    }
}

void set_tile_cell_sprite(board_t* board)
{
    for (int j = 0; j < board->height; ++j)
    {
        for (int i = 0; i < board->width; ++i)
        {
            tile_t tile;
            tile.width = UNIT_SIZE;
            tile.height = UNIT_SIZE;
            E_CELL_SPRITE index = get_cell_sprite(board, i, j);
            printf("index: %d\n", index);
            tile.row = index % 10;
            tile.column = index / 10;
            board->cells[i + j * board->width].tile = tile;
        }
    }
}

