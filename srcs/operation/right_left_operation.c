/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_left_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:07 by marai             #+#    #+#             */
/*   Updated: 2023/08/17 13:48:09 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_abs_left(t_vars *vars, double move_speed);
static void	move_abs_right(t_vars *vars, double move_speed);

void	move_left(t_vars *vars, double move_speed)
{
	if (vars->default_dir == North || vars->default_dir == East)
		move_abs_left(vars, move_speed);
	else
		move_abs_right(vars, move_speed);
}

void	move_right(t_vars *vars, double move_speed)
{
	if (vars->default_dir == North || vars->default_dir == East)
		move_abs_right(vars, move_speed);
	else
		move_abs_left(vars, move_speed);
}

static void	move_abs_left(t_vars *vars, double move_speed)
{
	if (vars->map[(int)(vars->pos_x + (vars->dir_x * cos(PI / 2) - vars->dir_y
				* sin(PI / 2)) * move_speed)][(int)vars->pos_y] == '0')
		vars->pos_x += (vars->dir_x * cos(PI / 2) - vars->dir_y * sin(PI / 2))
			* move_speed;
	if (vars->map[(int)(vars->pos_x)][(int)(vars->pos_y + (vars->dir_x * sin(PI
					/ 2) + vars->dir_y * cos(PI / 2)) * move_speed)] == '0')
		vars->pos_y += (vars->dir_x * sin(PI / 2) + vars->dir_y * cos(PI / 2))
			* move_speed;
}

static void	move_abs_right(t_vars *vars, double move_speed)
{
	if (vars->map[(int)(vars->pos_x + (vars->dir_x * cos(-PI / 2) - vars->dir_y
				* sin(-PI / 2)) * move_speed)][(int)vars->pos_y] == '0')
		vars->pos_x += (vars->dir_x * cos(-PI / 2) - vars->dir_y * sin(-PI / 2))
			* move_speed;
	if (vars->map[(int)(vars->pos_x)][(int)(vars->pos_y + (vars->dir_x * sin(-PI
					/ 2) + vars->dir_y * cos(-PI / 2)) * move_speed)] == '0')
		vars->pos_y += (vars->dir_x * sin(-PI / 2) + vars->dir_y * cos(-PI / 2))
			* move_speed;
}
