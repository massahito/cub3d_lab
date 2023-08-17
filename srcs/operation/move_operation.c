#include "cub3d.h"

static void	move_abs_left(t_vars *vars, double move_speed);
static void	move_abs_right(t_vars *vars, double move_speed);

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
