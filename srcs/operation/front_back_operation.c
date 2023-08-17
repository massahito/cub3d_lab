/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_back_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:03 by marai             #+#    #+#             */
/*   Updated: 2023/08/17 13:49:28 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forword(t_vars *vars, double move_speed)
{
	if (vars->map[(int)(vars->pos_x + vars->dir_x
			* move_speed)][(int)vars->pos_y] == '0')
		vars->pos_x += vars->dir_x * move_speed;
	if (vars->map[(int)(vars->pos_x)][(int)(vars->pos_y + vars->dir_y
			* move_speed)] == '0')
		vars->pos_y += vars->dir_y * move_speed;
}

void	move_back(t_vars *vars, double move_speed)
{
	if (vars->map[(int)(vars->pos_x - vars->dir_x
			* move_speed)][(int)vars->pos_y] == '0')
		vars->pos_x -= vars->dir_x * move_speed;
	if (vars->map[(int)(vars->pos_x)][(int)(vars->pos_y - vars->dir_y
			* move_speed)] == '0')
		vars->pos_y -= vars->dir_y * move_speed;
}
