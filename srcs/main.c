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

int	main(int argc, char **argv)
{
	t_vars			vars;
	t_texture_name	*texture_name;
	t_map_list		*map_list;

	texture_name = NULL;
	map_list = NULL;
	if (argc != 2)
	{
		error("Invalid argument", NULL, NULL);
		exit(EXIT_FAILURE);
	}
	if (check_file_name(argv[1]))
	{
		error("Invalid file name: ", argv[1], NULL);
		exit(EXIT_FAILURE);
	}
	read_cub_file(argv[1], &texture_name, &map_list);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d!");
	add_vars(&vars, texture_name, map_list);
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	calc(&vars);
	mlx_loop(vars.mlx);
}
