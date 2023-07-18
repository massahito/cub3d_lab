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
//calc.c
double	abs_double(double num);
//file_name.c
int		is_file_name_ok(char *str);
#endif
