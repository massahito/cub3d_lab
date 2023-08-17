#include "cub3d.h"

t_texture_name	*new_texture_name(void)
{
	t_texture_name	*texture_name;

	texture_name = malloc(sizeof(t_texture_name));
	if (!texture_name)
		malloc_err();
	texture_name->north = NULL;
	texture_name->south = NULL;
	texture_name->west = NULL;
	texture_name->east = NULL;
	texture_name->floor = NULL;
	texture_name->ceiling = NULL;
	return (texture_name);
}

void	free_azimuths(t_texture_name *texture_name)
{
	if (texture_name)
	{
		if (texture_name->north)
			free(texture_name->north);
		if (texture_name->south)
			free(texture_name->south);
		if (texture_name->west)
			free(texture_name->west);
		if (texture_name->east)
			free(texture_name->east);
		if (texture_name->floor)
			free(texture_name->floor);
		if (texture_name->ceiling)
			free(texture_name->ceiling);
		free(texture_name);
	}
}

int	fill_in_one_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == C)
			line[i] = '1';
		i++;
	}
	return (0);
}
