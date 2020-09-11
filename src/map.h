#ifndef __MAP_H_
#define __MAP_H_

#include <stdio.h>

typedef struct board_s board_t;

void read_map_file(char const* path_file, board_t* board);

#endif