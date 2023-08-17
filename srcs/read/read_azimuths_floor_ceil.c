#include "cub3d.h"

static t_texture	which_texture(char *line)
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

static char	*serch_texture_path(char *line, t_texture texture)
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

static int	add_texture(char **buf, char *line)
{
	if (*buf)
	{
		error("same texture", line, NULL);
		free(line);
		return (1);
	}
	*buf = ft_strdup(line);
	if (!(*buf))
		malloc_err();
	return (0);
}

static int	make_texture(t_texture_name **texture_name, t_texture texture,
		char **line)
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
		{
			return (error("Invalid file: ", "No azimuths or floor/ceiling",
					NULL));
		}
		line = delete_parts_not_needed_line(line);
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
