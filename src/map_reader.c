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
	
	
	
	free(line);
	fclose(file);
}