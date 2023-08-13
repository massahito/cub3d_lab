#include "cub3d.h"

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
		data = calc_dda(&x, &y);
		set_data(&data, vars, x, y);
		drawing(vars, i, data);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_texture_name *texture_name;
	t_map_list *map_list;

	/**
	 * 
	*/
	texture_name = NULL;
	map_list = NULL;
	if (argc != 2)
	{
		error("Invalid argument",NULL,NULL);
		exit(EXIT_FAILURE);
	}
    if(check_file_name(argv[1]))
	{
		error("Invalid file name: ",argv[1],NULL);
		exit(EXIT_FAILURE);
	}
	read_cub_file(argv[1],&texture_name,&map_list);
	/**
	 * 
	*/
	//init vars
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d!");
	// vars.pos_x = 22;
	// vars.pos_y = 12;
	// vars.plane_x = 0.66;
	// vars.plane_y = 0;
	//vars.dir_x = -1;
	//vars.dir_y = 0; 
	add_vars(&vars,texture_name,map_list);

/*
	vars.dir_x = -1;
	vars.dir_y = 0;
	vars.pos_x = 6;
	vars.pos_y = 8;
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
*/
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	//mlx_hook(vars.win, 17, 1L<<0, keypress, &vars);
	calc(&vars);
	mlx_loop(vars.mlx);
}
