#include <stdbool.h>

#include "map.h"
#include "board.h"
#include "defs.h"
#include "string_length.h"


bool is_hashtag(char c)
{
	if (c == '#')
		return true;

	return false;
}

bool is_X(char c)
{
	if (c == 'X')
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

char* read_line(FILE* file)
{
	if (file == NULL)
		return NULL;

	char* string_cpy = malloc((150) * sizeof(char));

	char* t = string_cpy;

	string_cpy = fgets(string_cpy, 150, file);

	int size = string_length(string_cpy);

	if (size == 0)
	{
		free(t);
		return NULL;
	}

	string_cpy = realloc(string_cpy, (size + 1) * sizeof(char));

	string_cpy[size] = '\0';

	if (string_cpy == NULL)
		return NULL;

	for (int i = 0; i < size; ++i)
		if (string_cpy[i] == '\n')
			string_cpy[i] = '\0';

	return string_cpy;
}

void read_map_file(char const* file_path, board_t* board)
{
	FILE* file = fopen(file_path, "rb");

	char* line = read_line(file);

	for (int i = 0; i < board->height; ++i)
	{
		for (int j = 0; j < board->width; ++j)
		{
			char c = line[j];
			cell_t cell;
			cell.is_wall = is_hashtag(c);

			cell.is_border = is_X(c);

			board->cells[j + i * board->width] = cell;
		}
		line = read_line(file);
	}


	free(line);
	
	fclose(file);
}
