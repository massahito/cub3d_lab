/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:12 by marai             #+#    #+#             */
/*   Updated: 2023/08/17 13:48:13 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn_abs_right(t_vars *vars, double rot_speed);
static void	turn_abs_left(t_vars *vars, double rot_speed);

void	turn_right(t_vars *vars, double rot_speed)
{
	if (vars->default_dir == North || vars->default_dir == East)
		turn_abs_right(vars, rot_speed);
	else
		turn_abs_left(vars, rot_speed);
}

void	turn_left(t_vars *vars, double rot_speed)
{
	if (vars->default_dir == North || vars->default_dir == East)
		turn_abs_left(vars, rot_speed);
	else
		turn_abs_right(vars, rot_speed);
}

static void	turn_abs_right(t_vars *vars, double rot_speed)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(-rot_speed) - vars->dir_y * sin(-rot_speed);
	vars->dir_y = olddir_x * sin(-rot_speed) + vars->dir_y * cos(-rot_speed);
	oldplane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(-rot_speed) - vars->plane_y
		* sin(-rot_speed);
	vars->plane_y = oldplane_x * sin(-rot_speed) + vars->plane_y
		* cos(-rot_speed);
}

static void	turn_abs_left(t_vars *vars, double rot_speed)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(rot_speed) - vars->dir_y * sin(rot_speed);
	vars->dir_y = olddir_x * sin(rot_speed) + vars->dir_y * cos(rot_speed);
	oldplane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(rot_speed) - vars->plane_y
		* sin(rot_speed);
	vars->plane_y = oldplane_x * sin(rot_speed) + vars->plane_y
		* cos(rot_speed);
}
