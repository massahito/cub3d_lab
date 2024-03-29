/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:47:56 by marai             #+#    #+#             */
/*   Updated: 2023/08/17 13:47:57 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress(int keycode, t_vars *vars)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.3;
	rot_speed = 0.2;
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == W_KEY)
		move_forword(vars, move_speed);
	else if (keycode == S_KEY)
		move_back(vars, move_speed);
	else if (keycode == A_KEY)
		move_left(vars, move_speed);
	else if (keycode == D_KEY)
		move_right(vars, move_speed);
	else if (keycode == R_ALW)
		turn_right(vars, rot_speed);
	else if (keycode == L_ALW)
		turn_left(vars, rot_speed);
	calc(vars);
	return (0);
}

void	set_value(t_vars *vars, t_x *x, t_y *y, double camera)
{
	x->ray_dir_x = vars->dir_x + vars->plane_x * camera;
	y->ray_dir_y = vars->dir_y + vars->plane_y * camera;
	x->map_x = (int)vars->pos_x;
	y->map_y = (int)vars->pos_y;
	if (x->ray_dir_x == 0)
		x->dlt_dist_x = 1e30;
	else
		x->dlt_dist_x = abs_double(1 / x->ray_dir_x);
	if (y->ray_dir_y == 0)
		y->dlt_dist_y = 1e30;
	else
		y->dlt_dist_y = abs_double(1 / y->ray_dir_y);
}

void	set_data(t_data *data, t_vars *vars, t_x x, t_y y)
{
	double	wall;

	if (data->side == 0)
	{
		wall = vars->pos_y + data->wall_dist * y.ray_dir_y;
		if (x.ray_dir_x < 0)
			data->img = vars->wall[0];
		else
			data->img = vars->wall[1];
	}
	else
	{
		wall = vars->pos_x + data->wall_dist * x.ray_dir_x;
		if (y.ray_dir_y < 0)
			data->img = vars->wall[2];
		else
			data->img = vars->wall[3];
	}
	wall = wall - floor(wall);
	data->tex_x = (int)(wall * (double)(data->img.img_width));
	if (data->side == 0 && x.ray_dir_x > 0)
		data->tex_x = data->img.img_width - data->tex_x - 1;
	else if (data->side == 1 && y.ray_dir_y < 0)
		data->tex_x = data->img.img_width - data->tex_x - 1;
	data->step = (1.0 * data->img.img_width) / data->wall_height;
}

int	mlx_destroy(int keycode)
{
	(void)keycode;
	exit(0);
}
