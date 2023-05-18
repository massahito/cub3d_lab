#ifndef CUB3D_H
#define CUB3D_H
// includes
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

//window size
#define WIN_WIDTH	640
#define WIN_HEIGHT	480

// linux keycode
#define ESC		65307
#define W_KEY	119
#define S_KEY	115
#define D_KEY	100
#define A_KEY	97
#define R_ALW	65363
#define L_ALW	65361
void	calc(t_vars *vars);
double abs_double(double num);
#endif