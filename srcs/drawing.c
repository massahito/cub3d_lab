#include "cub3d.h"

extern int worldMap[MAPWIDTH][MAPHEIGHT];


void	draw_ceiling(t_vars *vars, int line, t_data data)
{
	int	draw_start;
	int	j;

	j = 0;
	draw_start = -1 * data.wall_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	while(j < draw_start)
	{
		mlx_pixel_put(vars->mlx, vars->win, line, j, 0xfc5454);
		j++;
	}
}

void	draw_texture(t_vars *vars, int line, t_data data)
{
	int		j;
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
		- data.img.img_height / 2;
	j = draw_start;
	while(j < draw_end)
	{
		data.tex_y = (int)tex_pos & (data.img.img_height - 1);
		tex_pos += data.step;
		mlx_pixel_put(vars->mlx, vars->win, line, j, *(int *)(data.img.addr
				+ data.tex_y * data.img.size_len + data.tex_x
				* (data.img.bits_per_pixel / 8)));
		j++;
	}

}

void	draw_floor(t_vars *vars, int line, t_data data)
{
	int draw_end;
	int j;

	draw_end = data.wall_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	j = draw_end;
	while(j < WIN_HEIGHT)
	{
		mlx_pixel_put(vars->mlx, vars->win, line, j, 0x707070);
		j++;
	}
}

void	drawing(t_vars *vars, int line, t_data data)
{

	draw_ceiling(vars, line, data);
	draw_texture(vars, line, data);
	draw_floor(vars, line, data);
}
