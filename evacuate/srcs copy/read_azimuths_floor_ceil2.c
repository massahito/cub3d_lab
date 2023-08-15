#include "cub3d.h"

static int	change_floor_or_ceiling(t_texture_name **texture_name)
{
	if ((*texture_name)->floor)
	{
		if (check_number_comma((*texture_name)->floor))
			return (error("Error: ", "Invalid chara: ", "floor"));
		if (check_rgb((*texture_name)->floor))
			return (error("Error: ", "Invalid chara: ", "floor"));
		add_rgb(&(*texture_name)->f, (*texture_name)->floor);
	}
	if ((*texture_name)->ceiling)
	{
		if (check_number_comma((*texture_name)->ceiling))
			return (error("Error: ", "Invalid file: ", "ceiling"));
		if (check_rgb((*texture_name)->floor))
			return (error("Error: ", "Invalid chara: ", "ceiling"));
		add_rgb(&(*texture_name)->c, (*texture_name)->ceiling);
	}
	return (0);
}

int	texture_is_complete(t_texture_name *texture_name)
{
	if (texture_name->north == NULL)
		return (0);
	if (texture_name->south == NULL)
		return (0);
	if (texture_name->west == NULL)
		return (0);
	if (texture_name->east == NULL)
		return (0);
	if (texture_name->floor == NULL)
		return (0);
	if (texture_name->ceiling == NULL)
		return (0);
	return (1);
}

char	*delete_line_space(char *line)
{
	size_t	i;
	char	*return_value;

	i = 0;
	if (!line)
		return (NULL);
	while (ft_isspace(line[i]))
		i++;
	return_value = ft_strdup(&line[i]);
	free(line);
	return (return_value);
}

char	*delete_line_back_space(char *line)
{
	size_t	i;
	char	*return_value;

	if (!line)
		return (NULL);
	i = ft_strlen(line) - 1;
	while (ft_isspace(line[i]))
		i--;
	return_value = ft_substr(line, 0, i + 1);
	free(line);
	return (return_value);
}
