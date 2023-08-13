#include "cub3d.h"

static t_azimuth	which_azimuth(char *line)
{
	t_azimuth	re;

	while (isspace(*line))
		line++;
	if (strncmp(line, "NO", 2) == 0)
		re = North;
	else if (strncmp(line, "SO", 2) == 0)
		re = South;
	else if (strncmp(line, "WE", 2) == 0)
		re = West;
	else if (strncmp(line, "EA", 2) == 0)
		re = East;
	else if (no_line(line))
		re = AZIMUTH_No;
	else
		re = AZIMUTH_Vary;
	return (re);
}

static int	get_azimuth_texture_name_utils(char *texture_name,
											t_azimuth azimuth,
											t_texture_name **azimuths)
{
	if (azimuth == North)
	{
		if ((*azimuths)->north)
			return (1);
		(*azimuths)->north = texture_name;
	}
	else if (azimuth == South)
	{
		if ((*azimuths)->south)
			return (1);
		(*azimuths)->south = texture_name;
	}
	else if (azimuth == West)
	{
		if ((*azimuths)->west)
			return (1);
		(*azimuths)->west = texture_name;
	}
	else if (azimuth == East)
	{
		if ((*azimuths)->east)
			return (1);
		(*azimuths)->east = texture_name;
	}
	return (0);
}

static int	get_azimuth_texture_name(char *line, t_azimuth azimuth,
		t_texture_name **azimuths)
{
	char	*texture_name;

	while (isspace(*line))
		line++;
	line += 2;
	while (isspace(*line))
		line++;
	texture_name = strdup(line);
	if (!texture_name)
		malloc_err();
	return (get_azimuth_texture_name_utils(texture_name, azimuth, azimuths));
}

static int	read_azimuths_utils(char *line, t_texture_name **texture_name,
		int *n, t_azimuth azimuth)
{
	if (azimuth == AZIMUTH_No)
	{
		free(line);
		return (0);
	}
	*n += 1;
	if (get_azimuth_texture_name(line, azimuth, texture_name))
		return (error("Invalid file: ", "same azimuths", NULL));
	free(line);
	return (0);
}

int	read_azimuths(t_texture_name **texture_name, int fd)
{
	t_azimuth	azimuth;
	char		*line;
	int			n;

	n = 0;
	while (n < 4)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (error("Error: ", "Invalid file: ", "No azimuths"));
		line = delete_line_break(line);
		azimuth = which_azimuth(line);
		if (azimuth == AZIMUTH_Vary)
			return (error("Error: ", "Invalid file: ", "Vary azimuths"));
		if (read_azimuths_utils(line, texture_name, &n, azimuth))
			return (1);
	}
	return (0);
}
