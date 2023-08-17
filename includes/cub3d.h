#ifndef CUB3D_H
# define CUB3D_H
// includes
# include "get_next_line.h"
# include "libft.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

//window size
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define PI 3.141592653589793

// linux keycode
// # define EIXT_SUCCESS 0
// # define EXIT_FAILURE 1
// # define ESC 65307
// # define W_KEY 119
// # define S_KEY 115
// # define D_KEY 100
// # define A_KEY 97
// # define R_ALW 65363
// # define L_ALW 65361

//mac keycode
# define ESC 53
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define A_KEY 0
# define R_ALW 124
# define L_ALW 123

# define MAPWIDTH 24
# define MAPHEIGHT 24
/**    X  */
# define C 88

/**
 * add_vars
*/
void	add_vars(t_vars *vars, t_texture_name *texture_name,
		t_map_list *map_list);

/**
 * calc
*/
double	abs_double(double num);
void	calc(t_vars *vars);

/**
 * dda
*/
void	calc_first_step(t_vars *vars, t_x *x, t_y *y);
t_data	calc_dda(t_vars *vars, t_x *x, t_y *y);

/**
 * delete
*/
char	*delete_line_break(char *line);
char	*delete_parts_not_needed_line(char *line);
void	delete_map_space(t_map_list **map_list);

/**
 * drawing
*/
void	drawing(t_vars *vars, int line, t_data data);

/**
 * error
*/
int	error(char *str, char *str2, char *str3);
void	malloc_err(void);
void	read_err(char *meessage, int fd, t_texture_name **texture_name);

/**
 * file_check
*/
bool	check_file(char *str);

/**
 * map_check
*/
int	map_check(t_map_list **map_list);

/**
 * map_check2
*/
void	make_x_map(t_map_list *map_list);
void	surround(t_map_list **map_list);

/**
 * map_check3
*/
int	whether_possible_characters(char *line);
int	whether_player_is_right_or_not(char *line, size_t *player_count);
int	apply_list(t_map_list *map_list, int (*pfunc)(char *));
int	apply_list2(t_map_list *map_list, size_t *count, int (*pfunc)(char *,
			size_t *));
size_t	max_line_size(t_map_list *map_list);

/**
 * map_list
*/
t_map_list	*map_last(t_map_list *map_list);
t_map_list	*map_last(t_map_list *map_list);
t_map_list	*new_map_list(char *line);
void	add_map_list(t_map_list **map_list, char *line);
size_t	map_list_size(t_map_list *map_list);

/**
 * map_list2
*/
void	free_map_clear(t_map_list *map_list);
void	free_map_list(t_map_list *map_list);

/**
 * map_utils
*/
void	map_free(char **map);
char	**make_map(t_map_list *map_list);

/**
 * mlx_utils
*/
int	keypress(int keycode, t_vars *vars);
void	set_value(t_vars *vars, t_x *x, t_y *y, double camera);
void	set_data(t_data *data, t_vars *vars, t_x x, t_y y);
int mlx_destroy(int keycode);

/**
 * move_operation
*/
void	move_forword(t_vars *vars, double move_speed);
void	move_back(t_vars *vars, double move_speed);
void	move_left(t_vars *vars, double move_speed);
void	move_right(t_vars *vars, double move_speed);

/**
 * read_azimuths_floor_ceil
*/
int	read_azimuths_floor_ceil(t_texture_name **texture_name, int fd);

/**
 * read_azimuths_floor_ceil2
*/
int	change_floor_or_ceiling(t_texture_name **texture_name);
int	texture_is_complete(t_texture_name *texture_name);
bool	no_line(char *line);

/**
 * read_file
*/
void	read_cub_file(char *argv, t_texture_name **texture_name,
		t_map_list **map_list);

/**
 * read_file2
*/
t_texture_name	*new_texture_name(void);
void	free_azimuths(t_texture_name *texture_name);
int	fill_in_one_line(char *line);

/**
 * read_map
*/
bool	is_no_str(char *line);
int	read_map(t_map_list **map_list, int fd);

/**
 * rgb
*/
int	check_number_comma(char *str);
int	check_rgb(char *str);
int	change_rgb(int *n);

/**
 * rgb2
*/
void	add_rgb(int *num, char *str);

/**
 * rot_operation
*/
void	turn_right(t_vars *vars, double rot_speed);
void	turn_left(t_vars *vars, double rot_speed);

#endif
