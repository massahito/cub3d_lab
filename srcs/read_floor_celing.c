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

static int	check_number_comma(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && !ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}
static int	check_number_space(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}
static int	check_rgb(char *str)
{
	char	**arr;
	int		i;
	int		n;

	i = 0;
	arr = ft_split(str, ',');
	if (!arr)
		malloc_err();
	while (arr[i])
	{
		if (check_number_space(arr[i]))
		{
			ft_double_ptr_free(arr);
			return (1);
		}
		n = ft_atoi(arr[i]);
		if (n < 0 || 255 < n)
		{
			ft_double_ptr_free(arr);
			return (1);
		}
		i++;
	}
	if (i != 3)
	{
		ft_double_ptr_free(arr);
		return (1);
	}
	ft_double_ptr_free(arr);
	return (0);
}
static int	change_rgb(int *n)
{
	int	num;

	num = 0;
	num += (n[0] << 16);
	num += (n[1] << 8);
	num += (n[2]);
	return (num);
}

static void	add_rgb(int *num, char *str)
{
	char	**arr;
	int		i;
	int		n[3];

	i = 0;
	arr = ft_split(str, ',');
	if (!arr)
		malloc_err();
	while (arr[i])
	{
		n[i] = ft_atoi(arr[i]);
		i++;
	}
	ft_double_ptr_free(arr);
	*num = change_rgb(n);
}

static int	change_floor_or_ceiling(t_texture_name **texture_name)
{
	if ((*texture_name)->floor)
	{
		if (check_number_comma((*texture_name)->floor))
			return (error("Error: ", "Invalid chara: ", "floor", EXIT_FAILURE));
		if (check_rgb((*texture_name)->floor))
			return (error("Error: ", "Invalid chara: ", "floor", EXIT_FAILURE));
		add_rgb(&(*texture_name)->f, (*texture_name)->floor);
	}
	if ((*texture_name)->ceiling)
	{
		if (check_number_comma((*texture_name)->ceiling))
			return (error("Error: ", "Invalid file: ", "ceiling",
					EXIT_FAILURE));
		if (check_rgb((*texture_name)->floor))
			return (error("Error: ", "Invalid chara: ", "ceiling",
					EXIT_FAILURE));
		add_rgb(&(*texture_name)->c, (*texture_name)->ceiling);
	}
	return (0);
}

int	read_fc_color(t_texture_name **texture_name, int fd)
{
	char				*line;
	int					n;
	e_floor_or_ceiling	fc;

	n = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			return (error("Error: ", "Invalid file: ", "No Floor or Celing",
					EXIT_FAILURE));
		}
		line = delete_line_break(line);
		fc = which_fc(line);
		if (fc == FC_Vary)
		{
			return (error("Error: ", "Invalid file: ", "Vary Floor or Celing",
					EXIT_FAILURE));
		}
		else if (fc == FC_No)
		{
			free(line);
			continue ;
		}
		else
		{
			n += 1;
			if (get_fc_texture_name(line, fc, texture_name))
				return (error("Invalid file: ", "same floor or ceiling", NULL,
						EXIT_FAILURE));
		}
		free(line);
		if (n == 2)
			break ;
	}
	return (change_floor_or_ceiling(texture_name));
}
