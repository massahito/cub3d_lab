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

t_texture	which_texture(char *line)
{
	t_texture	return_value;

	if (ft_strncmp(line, "NO", 2) == 0)
		return_value = North;
	else if (ft_strncmp(line, "SO", 2) == 0)
		return_value = South;
	else if (ft_strncmp(line, "WE", 2) == 0)
		return_value = West;
	else if (ft_strncmp(line, "EA", 2) == 0)
		return_value = East;
	else if (ft_strncmp(line, "F", 1) == 0)
		return_value = Floor;
	else if (ft_strncmp(line, "C", 1) == 0)
		return_value = Ceiling;
	else if (no_line(line))
		return_value = NoTexture;
	else
		return_value = VaryTexture;
	return (return_value);
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

char	*serch_texture_path(char *line, t_texture texture)
{
	size_t	i;
	char	*newline;

	i = 0;
	if (texture == Floor || texture == Ceiling)
		i += 1;
	else
		i += 2;
	while (ft_isspace(line[i]))
		i++;
	newline = ft_strdup(&line[i]);
	if (!newline)
		malloc_err();
	free(line);
	return (newline);
}

int	add_texture(char **buf, char *line)
{
	if (*buf)
	{
		error("Error :", "same texture", line);
		free(line);
		return (1);
	}
	*buf = ft_strdup(line);
	if (!(*buf))
		malloc_err();
	return (0);
}

int	make_texture(t_texture_name **texture_name, t_texture texture, char **line)
{
	*line = serch_texture_path(*line, texture);
	if (texture == North)
		return (add_texture(&(*texture_name)->north, *line));
	if (texture == South)
		return (add_texture(&(*texture_name)->south, *line));
	if (texture == West)
		return (add_texture(&(*texture_name)->west, *line));
	if (texture == East)
		return (add_texture(&(*texture_name)->east, *line));
	if (texture == Floor)
		return (add_texture(&(*texture_name)->floor, *line));
	if (texture == Ceiling)
		return (add_texture(&(*texture_name)->ceiling, *line));
	return (0);
}

int	read_azimuths_floor_ceil(t_texture_name **texture_name, int fd)
{
	t_texture	texture;
	char		*line;

	while (texture_is_complete(*texture_name) == 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (error("Error: ", "Invalid file: ",
					"No azimuths or floor/ceiling"));
		line = delete_line_space(line);
		line = delete_line_break(line);
		line = delete_line_back_space(line);
		texture = which_texture(line);
		if (texture == VaryTexture)
			return (error("Invalid file: ", "Vary texture: ", line));
		if (texture != NoTexture)
		{
			if (make_texture(texture_name, texture, &line))
				return (1);
		}
		free(line);
	}
	return (change_floor_or_ceiling(texture_name));
}
