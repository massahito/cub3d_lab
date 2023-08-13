#include "cub3d.h"

static void	add_img(t_vars *vars, t_texture_name *texture_name,
		t_map_list *map_list)
{
	vars->wall[0].img = mlx_xpm_file_to_image(vars->mlx, texture_name->north,
		&(vars->wall[0].img_width), &(vars->wall[0].img_height));
	vars->wall[1].img = mlx_xpm_file_to_image(vars->mlx, texture_name->south,
		&(vars->wall[1].img_width), &(vars->wall[1].img_height));
	vars->wall[2].img = mlx_xpm_file_to_image(vars->mlx, texture_name->west,
		&(vars->wall[2].img_width), &(vars->wall[2].img_height));
	vars->wall[3].img = mlx_xpm_file_to_image(vars->mlx, texture_name->east,
		&(vars->wall[3].img_width), &(vars->wall[3].img_height));
	if (!vars->wall[0].img || !vars->wall[1].img || !vars->wall[2].img
		|| !vars->wall[0].img)
	{
		free_azimuths(texture_name);
		free_map_list(map_list);
		error("Error: ", "Invalid img: ", "wall img", EXIT_FAILURE);
		exit(1);
	}
}

static void	add_addr(t_vars *vars, t_texture_name *texture_name,
		t_map_list *map_list)
{
	vars->wall[0].addr = mlx_get_data_addr(vars->wall[0].img,
		&(vars->wall[0].bits_per_pixel), &(vars->wall[0].size_len),
		&(vars->wall[0].endian));
	vars->wall[1].addr = mlx_get_data_addr(vars->wall[1].img,
		&(vars->wall[1].bits_per_pixel), &(vars->wall[1].size_len),
		&(vars->wall[1].endian));
	vars->wall[2].addr = mlx_get_data_addr(vars->wall[2].img,
		&(vars->wall[2].bits_per_pixel), &(vars->wall[2].size_len),
		&(vars->wall[2].endian));
	vars->wall[3].addr = mlx_get_data_addr(vars->wall[3].img,
		&(vars->wall[3].bits_per_pixel), &(vars->wall[3].size_len),
		&(vars->wall[3].endian));
	free_azimuths(texture_name);
	free_map_list(map_list);
	if (!vars->wall[0].addr || !vars->wall[1].addr || !vars->wall[2].addr
		|| !vars->wall[0].addr)
	{
		error("Error: ", "Invalid addr: ", "wall addr", EXIT_FAILURE);
		exit(1);
	}
}

static void	add_direction(t_vars *vars, t_texture_name *texture_name)
{
	if (texture_name->direction == North)
	{
		vars->dir_x = 0;
		vars->dir_y = 1;
		vars->plane_x = 0.66;
		vars->plane_y = 0;
	}
	if (texture_name->direction == South)
	{
		vars->dir_x = 0;
		vars->dir_y = -1;
		vars->plane_x = 0.66;
		vars->plane_y = 0;
	}
	if (texture_name->direction == West)
	{
		vars->dir_x = -1;
		vars->dir_y = 0;
		vars->plane_x = 0;
		vars->plane_y = 0.66;
	}
	if (texture_name->direction == East)
	{
		vars->dir_x = 1;
		vars->dir_y = 0;
		vars->plane_x = 0;
		vars->plane_y = 0.66;
	}
}

void	add_vars(t_vars *vars, t_texture_name *texture_name,
		t_map_list *map_list)
{
	vars->map = make_map(map_list);
	add_img(vars, texture_name, map_list);
	add_addr(vars, texture_name, map_list);
	add_direction(vars, texture_name);
	vars->floor = texture_name->f;
	vars->ceiling = texture_name->c;
	vars->pos_x = texture_name->pos_x;
	vars->pos_y = texture_name->pos_y;
}
