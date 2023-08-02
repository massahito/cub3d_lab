#ifndef CUB3D_H
# define CUB3D_H
// includes
# include "struct.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

//window size
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define PI 3.141592653589793

// linux keycode
/*
# define ESC		65307
# define W_KEY	119
# define S_KEY	115
# define D_KEY	100
# define A_KEY	97
# define R_ALW	65363
# define L_ALW	65361
*/

//mac keycode
# define ESC 53
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define A_KEY 0
# define R_ALW 124
# define L_ALW 123

//function prototypes
//main.c
void	calc(t_vars *vars);

//move_operation.c
void	move_forword(t_vars *vars, double move_speed);
void	move_back(t_vars *vars, double move_speed);
void	move_left(t_vars *vars, double move_speed);
void	move_right(t_vars *vars, double move_speed);

//rot_operation
void	turn_left(t_vars *vars, double rot_speed);
void	turn_right(t_vars *vars, double rot_speed);
//calc.c
double	abs_double(double num);

//dda
void	calc_first_step(t_vars *vars, t_x *x, t_y *y);
t_data	calc_dda(t_x *x, t_y *y);

//drawing
void	drawing(t_vars *vars, int i, t_data data);
//file_name.c
int		is_file_name_ok(char *str);

//tmp
#define MAPWIDTH 24
#define MAPHEIGHT 24
#endif
