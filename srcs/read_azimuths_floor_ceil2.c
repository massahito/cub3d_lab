#include "cub3d.h"

int	change_floor_or_ceiling(t_texture_name **texture_name)
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
