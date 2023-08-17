/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:47:37 by marai             #+#    #+#             */
/*   Updated: 2023/08/17 13:49:19 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	abs_double(double num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

void	calc(t_vars *vars)
{
	int		i;
	double	camera;
	t_x		x;
	t_y		y;
	t_data	data;

	i = 0;
	while (i < WIN_WIDTH)
	{
		camera = 2 * i / (double)WIN_WIDTH - 1;
		set_value(vars, &x, &y, camera);
		calc_first_step(vars, &x, &y);
		data = calc_dda(vars, &x, &y);
		set_data(&data, vars, x, y);
		drawing(vars, i, data);
		i++;
	}
	return ;
}
