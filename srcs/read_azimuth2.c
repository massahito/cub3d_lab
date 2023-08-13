#include "cub3d.h"

bool	no_line(char *line)
{
	while (isspace(*line))
		line++;
	if (strncmp(line, "\0", 1) == 0)
		return (true);
	return (false);
}
