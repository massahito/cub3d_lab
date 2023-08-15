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
# define EIXT_SUCCESS 0
# define EXIT_FAILURE 1
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define R_ALW 65363
# define L_ALW 65361

//mac keycode
//# define ESC 53
//# define W_KEY 13
//# define S_KEY 1
//# define D_KEY 2
//# define A_KEY 0
//# define R_ALW 124
//# define L_ALW 123

//function prototypes
//main.c
void			calc(t_vars *vars);

//move_operation.c
void			move_forword(t_vars *vars, double move_speed);
void			move_back(t_vars *vars, double move_speed);
void			move_left(t_vars *vars, double move_speed);
void			move_right(t_vars *vars, double move_speed);

//rot_operation
void			turn_left(t_vars *vars, double rot_speed);
void			turn_right(t_vars *vars, double rot_speed);
//calc.c
double			abs_double(double num);

//dda
void			calc_first_step(t_vars *vars, t_x *x, t_y *y);
t_data			calc_dda(t_vars *vars, t_x *x, t_y *y);

//drawing
void			drawing(t_vars *vars, int i, t_data data);
//file_name.c
int				is_file_name_ok(char *str);

//tmp
# define MAPWIDTH 24
# define MAPHEIGHT 24

/**
 * 
*/
// int			error(char *str, char *str2, char *str3, size_t exit_status);
int				error(char *str, char *str2, char *str3);
bool			check_file_name(char *str);
void			free_azimuths(t_texture_name *texture_name);
int				read_azimuths(t_texture_name **texture_name, int fd);
int				read_fc_color(t_texture_name **texture_name, int fd);
int				read_map(t_map_list **map_list, int fd);
void			free_map_list(t_map_list *map_list);
int				map_check(t_map_list **map_list);
char			**make_map(t_map_list *map_list);
void			map_free(char **map);
size_t			map_list_size(t_map_list *map_list);
t_map_list		*map_last(t_map_list *map_list);
t_map_list		*new_map_list(char *line);
// void read_cub_file(char *argv);
void			read_cub_file(char *argv, t_texture_name **texture_name,
					t_map_list **map_list);
char			*delete_line_break(char *line);
bool	is_no_str(char *line);
int				apply_list(t_map_list *map_list, int (*pfunc)(char *));
bool			no_line(char *line);
void			add_vars(t_vars *vars, t_texture_name *texture_name,
					t_map_list *map_list);
/*map_check2**/
void			move_line(char *line, char *newline);
void			remake_line(t_map_list *map_list, size_t max_size);
void			make_x_map(t_map_list *map_list);
char			*make_x_line(char *line, size_t size, char c);
void			surround(t_map_list **map_list);
/**map_check3*/
size_t			max_line_size(t_map_list *map_list);
int				apply_list2(t_map_list *map_list, size_t *count,
					int (*pfunc)(char *, size_t *));
int				whether_player_is_right_or_not(char *line,
					size_t *player_count);
int				whether_possible_characters(char *line);
void			read_err(char *meessage, int fd, t_texture_name **texture_name);
int				fill_in_one_line(char *line);
void			free_azimuths(t_texture_name *texture_name);
t_texture_name	*new_texture_name(void);
int				check_number_comma(char *str);
void			malloc_err(void);
int				check_number_space(char *str);
int				check_rgb(char *str);
void			add_rgb(int *num, char *str);
int				change_rgb(int *n);
int	change_floor_or_ceiling(t_texture_name **texture_name);
int	texture_is_complete(t_texture_name *texture_name);
// t_map_list	*map_last(t_map_list *map_list);
// t_map_list	*new_map_list(char *line);
// void	add_map_list(t_map_list **map_list, char *line);
// size_t	map_list_size(t_map_list *map_list);
// void	free_map_clear(t_map_list *map_list);
size_t			map_list_size(t_map_list *map_list);
void			add_map_list(t_map_list **map_list, char *line);
t_map_list		*new_map_list(char *line);
t_map_list		*map_last(t_map_list *map_list);
void			free_map_clear(t_map_list *map_list);
void			free_map_list(t_map_list *map_list);
char *delete_parts_not_needed_line(char *line);
void	delete_map_space(t_map_list **map_list);

int read_azimuths_floor_ceil(t_texture_name **texture_name, int fd);
/**    X  */
# define C 88
/**    1  */
// #define C 49
// # define MALLOC_ERR error("malloc error", NULL, NULL, EXIT_FAILURE)

#endif
