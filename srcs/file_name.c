#include "cub3d.h"
#include <string.h>

int	is_file_name_ok(char *str)
{
	if(!str || strlen(str) < 4)
		return (0);
	else if(strcmp(&(str[strlen(str) - 4]), ".cub"))
		return (0);
	return (1);
}