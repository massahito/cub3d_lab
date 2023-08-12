#include "cub3d.h"

bool	check_file_name(char *str)
{
	if (!str || strlen(str) < 4)
		return (true);
	else if (strncmp(&(str[strlen(str) - 4]), ".cub", 4))
		return (true);
	return (false);
}
