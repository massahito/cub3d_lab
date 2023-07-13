#ifndef STRUCT_H
#define STRUCT_H

typedef struct	s_img {
	void	*img;
	int		img_height;
	int		img_width;
	char	*addr;
	int		bits_per_pixel;
	int		size_len;
	int		endian;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	t_img	sample;
}	t_vars;

typedef struct s_x
{
	int		map_x;
	int		step_x;
	double	ray_dir_x;
	double	side_dist_x;
	double	dlt_dist_x;
} t_x;

typedef struct s_y
{
	int		map_y;
	int		step_y;
	double	ray_dir_y;
	double	side_dist_y;
	double	dlt_dist_y;
}		t_y;



#endif