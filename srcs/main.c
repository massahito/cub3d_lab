#include "cub3d.h"
#define MAPWIDTH 24
#define MAPHEIGHT 24
#define PI 3.141592653589793

/*
int worldMap[MAPWIDTH][MAPHEIGHT]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
*/

int	keypress(int keycode, t_vars *vars)
{
	double	move_speed;
	double	rot_speed;
	double	olddir_x;
	double	oldplane_x;

	move_speed = 0.3;
	rot_speed = 0.2;
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == W_KEY)
	{
		if (worldMap[(int)(vars->pos_x + vars->dir_x
				* move_speed)][(int)vars->pos_y] == 0)
			vars->pos_x += vars->dir_x * move_speed;
		if (worldMap[(int)(vars->pos_x)][(int)(vars->pos_y + vars->dir_y
				* move_speed)] == 0)
			vars->pos_y += vars->dir_y * move_speed;
	}
	else if (keycode == S_KEY)
	{
		if (worldMap[(int)(vars->pos_x - vars->dir_x
				* move_speed)][(int)vars->pos_y] == 0)
			vars->pos_x -= vars->dir_x * move_speed;
		if (worldMap[(int)(vars->pos_x)][(int)(vars->pos_y - vars->dir_y
				* move_speed)] == 0)
			vars->pos_y -= vars->dir_y * move_speed;
	}
	else if (keycode == A_KEY)
	{
		if (worldMap[(int)(vars->pos_x + (vars->dir_x * cos(PI / 2)
					- vars->dir_y * sin(PI / 2))
				* move_speed)][(int)vars->pos_y] == 0)
			vars->pos_x += (vars->dir_x * cos(PI / 2) - vars->dir_y * sin(PI
						/ 2)) * move_speed;
		if (worldMap[(int)(vars->pos_x)][(int)(vars->pos_y + (vars->dir_x
					* sin(PI / 2) + vars->dir_y * cos(PI / 2))
				* move_speed)] == 0)
			vars->pos_y += (vars->dir_x * sin(PI / 2) + vars->dir_y * cos(PI
						/ 2)) * move_speed;
	}
	else if (keycode == D_KEY)
	{
		if (worldMap[(int)(vars->pos_x + (vars->dir_x * cos(-PI / 2)
					- vars->dir_y * sin(-PI / 2))
				* move_speed)][(int)vars->pos_y] == 0)
			vars->pos_x += (vars->dir_x * cos(-PI / 2) - vars->dir_y * sin(-PI
						/ 2)) * move_speed;
		if (worldMap[(int)(vars->pos_x)][(int)(vars->pos_y + (vars->dir_x
					* sin(-PI / 2) + vars->dir_y * cos(-PI / 2))
				* move_speed)] == 0)
			vars->pos_y += (vars->dir_x * sin(-PI / 2) + vars->dir_y * cos(-PI
						/ 2)) * move_speed;
	}
	else if (keycode == R_ALW)
	{
		olddir_x = vars->dir_x;
		vars->dir_x = vars->dir_x * cos(-rot_speed) - vars->dir_y
			* sin(-rot_speed);
		vars->dir_y = olddir_x * sin(-rot_speed) + vars->dir_y
			* cos(-rot_speed);
		oldplane_x = vars->plane_x;
		vars->plane_x = vars->plane_x * cos(-rot_speed) - vars->plane_y
			* sin(-rot_speed);
		vars->plane_y = oldplane_x * sin(-rot_speed) + vars->plane_y
			* cos(-rot_speed);
	}
	else if (keycode == L_ALW)
	{
		olddir_x = vars->dir_x;
		vars->dir_x = vars->dir_x * cos(rot_speed) - vars->dir_y
			* sin(rot_speed);
		vars->dir_y = olddir_x * sin(rot_speed) + vars->dir_y * cos(rot_speed);
		oldplane_x = vars->plane_x;
		vars->plane_x = vars->plane_x * cos(rot_speed) - vars->plane_y
			* sin(rot_speed);
		vars->plane_y = oldplane_x * sin(rot_speed) + vars->plane_y
			* cos(rot_speed);
	}
	calc(vars);
	return (0);
}

void	set_value(t_vars *vars, t_x *x, t_y *y, double camera)
{
	x->ray_dir_x = vars->dir_x + vars->plane_x * camera;
	y->ray_dir_y = vars->dir_y + vars->plane_y * camera;
	x->map_x = (int)vars->pos_x;
	y->map_y = (int)vars->pos_y;
	x->dlt_dist_x = (x->ray_dir_x == 0) ? 1e30 : abs_double(1 / x->ray_dir_x);
	y->dlt_dist_y = (y->ray_dir_y == 0) ? 1e30 : abs_double(1 / y->ray_dir_y);
}

void	first_step(t_vars *vars, t_x *x, t_y *y)
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
t_data	calc_dda(t_x *x, t_y *y)
{
	int		hit;
	int		side;
	t_data	data;

	hit = 0;
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
	data.side = side;
	if (side == 0)
		data.wall_dist = (x->side_dist_x - x->dlt_dist_x);
	else
		data.wall_dist = (y->side_dist_y - y->dlt_dist_y);
	data.wall_height = WIN_HEIGHT / data.wall_dist;
	return (data);
}

void	drawing(t_vars *vars, int i, t_data data)
{
	int		draw_start;
	int		draw_end;
	double	tex_pos;

	draw_start = -1 * data.wall_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = data.wall_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	tex_pos = (draw_start - WIN_HEIGHT / 2 + data.wall_dist / 2) * data.step
		- vars->sample.img_height / 2;
	for (int j = 0; j < draw_start; j++)
		mlx_pixel_put(vars->mlx, vars->win, i, j, 0xfc5454);
	for (int j = draw_start; j < draw_end; j++)
	{
		data.tex_y = (int)tex_pos & (vars->sample.img_height - 1);
		tex_pos += data.step;
		mlx_pixel_put(vars->mlx, vars->win, i, j, *(int *)(vars->sample.addr
					+ data.tex_y * vars->sample.size_len + data.tex_x
					* (vars->sample.bits_per_pixel / 8)));
	}
	for (int j = draw_end; j < WIN_HEIGHT; j++)
		mlx_pixel_put(vars->mlx, vars->win, i, j, 0x707070);
}

void	set_data(t_data *data, t_vars *vars, t_x x, t_y y)
{
	double	wall;

	if (data->side == 0)
	{
		wall = vars->pos_y + data->wall_dist * y.ray_dir_y;
		if (x.ray_dir_x < 0)
			vars->sample = vars->wall[0];
		else
			vars->sample = vars->wall[1];
	}
	else
	{
		wall = vars->pos_x + data->wall_dist * x.ray_dir_x;
		if (y.ray_dir_y < 0)
			vars->sample = vars->wall[2];
		else
			vars->sample = vars->wall[3];
	}
	wall = wall - floor(wall);
	data->tex_x = (int)(wall * (double)(vars->sample.img_width));
	if (data->side == 0 && x.ray_dir_x > 0)
		data->tex_x = vars->sample.img_width - data->tex_x - 1;
	else if (data->side == 1 && y.ray_dir_y < 0)
		data->tex_x = vars->sample.img_width - data->tex_x - 1;
	data->step = (1.0 * vars->sample.img_width) / data->wall_height;
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
		first_step(vars, &x, &y);
		data = calc_dda(&x, &y);
		set_data(&data, vars, x, y);
		drawing(vars, i, data);
		i++;
	}
	return ;
}

int	main(void)
{
	t_vars	vars;
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;

	//init vars
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d!");
	vars.dir_x = -1;
	vars.dir_y = 0;
	vars.pos_x = 22;
	vars.pos_y = 12;
	vars.plane_x = 0;
	vars.plane_y = 0.66;
	//iamge download
	img0 = mlx_xpm_file_to_image(vars.mlx, "./images/komurokei.xpm",
			&(vars.wall[0].img_width), &(vars.wall[0].img_height));
	vars.wall[0].addr = mlx_get_data_addr(img0, &(vars.wall[0].bits_per_pixel),
			&(vars.wall[0].size_len), &(vars.wall[0].endian));
	img1 = mlx_xpm_file_to_image(vars.mlx, "./images/bluestone.xpm",
			&(vars.wall[1].img_width), &(vars.wall[1].img_height));
	vars.wall[1].addr = mlx_get_data_addr(img1, &(vars.wall[1].bits_per_pixel),
			&(vars.wall[1].size_len), &(vars.wall[1].endian));
	img2 = mlx_xpm_file_to_image(vars.mlx, "./images/colorstone.xpm",
			&(vars.wall[2].img_width), &(vars.wall[2].img_height));
	vars.wall[2].addr = mlx_get_data_addr(img2, &(vars.wall[2].bits_per_pixel),
			&(vars.wall[2].size_len), &(vars.wall[2].endian));
	img3 = mlx_xpm_file_to_image(vars.mlx, "./images/greystone.xpm",
			&(vars.wall[3].img_width), &(vars.wall[3].img_height));
	vars.wall[3].addr = mlx_get_data_addr(img3, &(vars.wall[3].bits_per_pixel),
			&(vars.wall[3].size_len), &(vars.wall[3].endian));
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	//mlx_hook(vars.win, 17, 1L<<0, keypress, &vars);
	calc(&vars);
	mlx_loop(vars.mlx);
}
