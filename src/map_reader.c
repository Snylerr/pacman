#include <stdbool.h>

#include "map.h"
#include "board.h"
#include "defs.h"


bool is_hashtag(char c)
{
	if (c == '#')
		return true;

	return false;
}

int	read_char(FILE* file, char* pointer_c)
{
	if (file == NULL || pointer_c == NULL)
		return 0;
	char c = fgetc(file);

	if (feof(file) != 0)	
		return 0;

	*pointer_c = c;

	return 1;
}

void read_map_file(char const* file_path, board_t* board)
{
	FILE* file = fopen(file_path, "rb");

	char c = ' ';

	read_char(file, &c);

	for (int i = 0; i < board->height; ++i)
	{
		for (int j = 0; j < board->width; ++j)
		{
			cell_t cell;
			cell.is_wall = is_hashtag(c);
			board->cells[j + i * board->width] = cell;
		}
	}

	fclose(file);
}