#include "cub3d.h"

extern int worldMap[MAPWIDTH][MAPHEIGHT];

void	calc_first_step(t_vars *vars, t_x *x, t_y *y)
{
	if (x->ray_dir_x < 0)
	{
		x->step_x = -1;
		x->side_dist_x = (vars->pos_x - x->map_x) * x->dlt_dist_x;
	}
	else
	{
		x->step_x = 1;
		x->side_dist_x = (x->map_x + 1.0 - vars->pos_x) * x->dlt_dist_x;
	}
	if (y->ray_dir_y < 0)
	{
		y->step_y = -1;
		y->side_dist_y = (vars->pos_y - y->map_y) * y->dlt_dist_y;
	}
	else
	{
		y->step_y = 1;
		y->side_dist_y = (y->map_y + 1.0 - vars->pos_y) * y->dlt_dist_y;
	}
}

static int	calc_side(t_x *x, t_y *y)
{
	int		hit;
	int		side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
		if (x->side_dist_x < y->side_dist_y)
		{
			x->side_dist_x += x->dlt_dist_x;
			x->map_x += x->step_x;
			side = 0;
		}
		else
		{
			y->side_dist_y += y->dlt_dist_y;
			y->map_y += y->step_y;
			side = 1;
		}
		if (worldMap[x->map_x][y->map_y] > 0)
			hit = 1;
	}
	return (side);
}

t_data	calc_dda(t_x *x, t_y *y)
{
	t_data	data;

	data.side = calc_side(x, y);
	if (data.side == 0)
		data.wall_dist = (x->side_dist_x - x->dlt_dist_x);
	else
		data.wall_dist = (y->side_dist_y - y->dlt_dist_y);
	data.wall_height = WIN_HEIGHT / data.wall_dist;
	return (data);
}
