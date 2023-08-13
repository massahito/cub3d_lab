#include "cub3d.h"

static e_floor_or_ceiling	which_fc(char *line)
{
	e_floor_or_ceiling	re;

	while (isspace(*line))
		line++;
	if (strncmp(line, "F", 1) == 0)
		re = Floor;
	else if (strncmp(line, "C", 1) == 0)
		re = Ceiling;
	else if (no_line(line))
		re = FC_No;
	else
		re = FC_Vary;
	return (re);
}

static int	get_fc_texture_name(char *line, e_floor_or_ceiling fc,
		t_texture_name **texture_name)
{
	char	*name;

	while (isspace(*line))
		line++;
	line += 1;
	while (isspace(*line))
		line++;
	name = strdup(line);
	if (!name)
		malloc_err();
	if (fc == Floor)
	{
		if ((*texture_name)->floor)
			return (1);
		(*texture_name)->floor = name;
	}
	else if (fc == Ceiling)
	{
		if ((*texture_name)->ceiling)
			return (1);
		(*texture_name)->ceiling = name;
	}
	return (0);
}

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

static int	read_fc_color_utils(e_floor_or_ceiling fc, char *line,
		t_texture_name **texture_name, int *n)
{
	if (fc == FC_No)
	{
		free(line);
		return (0);
	}
	else
	{
		*n += 1;
		if (get_fc_texture_name(line, fc, texture_name))
			return (error("Invalid file: ", "same floor or ceiling", NULL));
	}
	free(line);
	return (0);
}

int	read_fc_color(t_texture_name **texture_name, int fd)
{
	char				*line;
	int					n;
	e_floor_or_ceiling	fc;

	n = 0;
	while (n < 2)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (error("Error: ", "Invalid file: ", "No Floor or Celing"));
		line = delete_line_break(line);
		fc = which_fc(line);
		if (fc == FC_Vary)
			return (error("Error: ", "Invalid file: ", "Vary Floor or Celing"));
		if (read_fc_color_utils(fc, line, texture_name, &n))
			return (1);
	}
	return (change_floor_or_ceiling(texture_name));
}
