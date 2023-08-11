#include "cub3d.h"

void	add_vars(t_vars *vars, t_texture_name *texture_name,
		t_map_list *map_list)
{
	vars->map = make_map(map_list);
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
	vars->wall[0].addr = mlx_get_data_addr(vars->wall[0].img,
											&(vars->wall[0].bits_per_pixel),
											&(vars->wall[0].size_len),
											&(vars->wall[0].endian));
	vars->wall[1].addr = mlx_get_data_addr(vars->wall[1].img,
											&(vars->wall[1].bits_per_pixel),
											&(vars->wall[1].size_len),
											&(vars->wall[1].endian));
	vars->wall[2].addr = mlx_get_data_addr(vars->wall[2].img,
											&(vars->wall[2].bits_per_pixel),
											&(vars->wall[2].size_len),
											&(vars->wall[2].endian));
	vars->wall[3].addr = mlx_get_data_addr(vars->wall[3].img,
											&(vars->wall[3].bits_per_pixel),
											&(vars->wall[3].size_len),
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
