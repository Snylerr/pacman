#ifndef __DEFS__
#define __DEFS__

// 28 tiles width 896
// 31 tiles height 1088

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

#define BOARD_WIDTH 28
#define BOARD_HEIGHT 31

#define UNIT_SIZE 16

#define OFFSET 32

#define MARGE 1.f

#define PLAYER_START_X 12
#define PLAYER_START_Y 12
#define PLAYER_SPEED 5

#define MAX_ENEMIES 4

// const int width = BOARD_WIDTH * UNIT_SIZE;
// const int height = BOARD_HEIGHT * UNIT_SIZE;


typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT,

    NONE
}E_DIR;


#endif
