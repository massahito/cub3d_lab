#include "cub3d.h"

bool	check_file(char *str)
{
	int fd;

	if (!str || strlen(str) < 4)
	{
		error("Invalid file name: ", str, NULL);
		return (true);
	}
	else if (strncmp(&(str[strlen(str) - 4]), ".cub", 4))
	{
		error("Invalid file name: ", str, NULL);
		return (true);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	 {
		error("File open error: ", str, NULL);
		return true;
	 }
	return (false);
}
