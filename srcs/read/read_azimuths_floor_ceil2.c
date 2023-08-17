/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_azimuths_floor_ceil2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:42:00 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 18:08:35 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	change_floor_or_ceiling(t_texture_name **texture_name)
{
	if ((*texture_name)->floor)
	{
		if (check_number_comma((*texture_name)->floor))
			return (error("Invalid character: ", "floor", NULL));
		if (check_rgb((*texture_name)->floor))
			return (error("Invalid character: ", "floor", NULL));
		add_rgb(&(*texture_name)->f, (*texture_name)->floor);
	}
	if ((*texture_name)->ceiling)
	{
		if (check_number_comma((*texture_name)->ceiling))
			return (error("Invalid file: ", "ceiling", NULL));
		if (check_rgb((*texture_name)->ceiling))
			return (error("Invalid character:", "ceiling", NULL));
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

bool	no_line(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (ft_strncmp(line, "\0", 1) == 0)
		return (true);
	return (false);
}
