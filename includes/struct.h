#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void					*img;
	int						img_height;
	int						img_width;
	char					*addr;
	int						bits_per_pixel;
	int						size_len;
	int						endian;
}							t_img;

typedef struct s_vars
{
	void					*mlx;
	void					*win;
	double					pos_x;
	double					pos_y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
	char					**map;
	int						floor;	
	int						ceiling;
	t_img					wall[4];
}							t_vars;

typedef struct s_x
{
	int						map_x;
	int						step_x;
	double					ray_dir_x;
	double					side_dist_x;
	double					dlt_dist_x;
}							t_x;

typedef struct s_y
{
	int						map_y;
	int						step_y;
	double					ray_dir_y;
	double					side_dist_y;
	double					dlt_dist_y;
}							t_y;

typedef struct s_data
{
	int						side;
	double					wall_dist;
	int						wall_height;
	int						tex_x;
	int						tex_y;
	double					tex_position;
	double					step;
	t_img					img;
}							t_data;

/**
 * 
*/
typedef enum azimuth
{
	North,
	South,
	West,
	East,
	AZIMUTH_Vary,
	AZIMUTH_No,
}							e_azimuth;

typedef struct s_texture_name
{
	char					*north;
	char					*south;
	char					*west;
	char					*east;
	char					*floor;
	char					*ceiling;
	int						c;
	int						f;
	double					pos_x;
	double					pos_y;
	e_azimuth					direction;

}							t_texture_name;

typedef enum floor_or_ceiling
{
	Floor,
	Ceiling,
	FC_Vary,
	FC_No,
}							e_floor_or_ceiling;

typedef struct s_map_list	t_map_list;
struct						s_map_list
{
	char					*line;
	t_map_list				*next;
	t_map_list				*prev;
};
#endif
