#include "cub3d.h"
#define mapWidth 24
#define mapHeight 24
static const double pi = 3.141592653589793;
int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


void	my_mlx_pixel_put(t_img data, int x, int y, int color)
{
	char	*dst;

	dst = data.addr + (y * data.size_len + x * (data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int keypress(int keycode, t_vars *vars)
{
  double moveSpeed = 0.3;
  double rotSpeed = 0.2;

  if (keycode == ESC)
  {
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
  }
  else if(keycode == W_KEY)
  {
      if(worldMap[(int) (vars->posX + vars->dirX * moveSpeed)][(int)vars->posY] == 0) vars->posX += vars->dirX * moveSpeed;
      if(worldMap[(int) (vars->posX)][(int) (vars->posY + vars->dirY * moveSpeed)] == 0) vars->posY += vars->dirY * moveSpeed;

  }
  else if(keycode == S_KEY)
  {
    if(worldMap[(int) (vars->posX - vars->dirX * moveSpeed)][(int) vars->posY] == 0) vars->posX -= vars->dirX * moveSpeed;
    if(worldMap[(int) (vars->posX)][(int) (vars->posY - vars->dirY * moveSpeed)] == 0) vars->posY -= vars->dirY * moveSpeed;
  }
  else if(keycode == A_KEY)
  {
    if(worldMap[(int) (vars->posX + (vars->dirX * cos(pi/2) - vars->dirY * sin(pi/2)) * moveSpeed)][(int)vars->posY] == 0) vars->posX += (vars->dirX * cos(pi/2) - vars->dirY * sin(pi/2)) * moveSpeed;
    if(worldMap[(int) (vars->posX)][(int) (vars->posY + (vars->dirX * sin(pi/2) + vars->dirY * cos(pi/2))* moveSpeed)] == 0) vars->posY += (vars->dirX * sin(pi/2) + vars->dirY * cos(pi/2)) * moveSpeed;
  }
  else if(keycode == D_KEY)
  {
    if(worldMap[(int) (vars->posX + (vars->dirX * cos(-pi/2) - vars->dirY * sin(-pi/2))* moveSpeed)][(int)vars->posY] == 0) vars->posX +=  (vars->dirX * cos(-pi/2) - vars->dirY * sin(-pi/2)) * moveSpeed;
    if(worldMap[(int) (vars->posX)][(int) (vars->posY + (vars->dirX * sin(-pi/2) + vars->dirY * cos(-pi/2))* moveSpeed)] == 0) vars->posY += (vars->dirX * sin(-pi/2) + vars->dirY * cos(-pi/2)) * moveSpeed;
  }
  else if(keycode == R_ALW)
  {
    double oldDirX = vars->dirX;
    vars->dirX = vars->dirX * cos(-rotSpeed) - vars->dirY * sin(-rotSpeed);
    vars->dirY = oldDirX * sin(-rotSpeed) + vars->dirY * cos(-rotSpeed);
    double oldPlaneX = vars->planeX;
    vars->planeX = vars->planeX * cos(-rotSpeed) - vars->planeY * sin(-rotSpeed);
    vars->planeY = oldPlaneX * sin(-rotSpeed) + vars->planeY * cos(-rotSpeed);
  }
  else if(keycode == L_ALW)
  {
    double oldDirX = vars->dirX;
    vars->dirX = vars->dirX * cos(rotSpeed) - vars->dirY * sin(rotSpeed);
    vars->dirY = oldDirX * sin(rotSpeed) + vars->dirY * cos(rotSpeed);
    double oldPlaneX = vars->planeX;
    vars->planeX = vars->planeX * cos(rotSpeed) - vars->planeY * sin(rotSpeed);
    vars->planeY = oldPlaneX * sin(rotSpeed) + vars->planeY * cos(rotSpeed);
  }
  calc(vars);
  return (0);
}
void  set_value(t_vars *vars, t_x *x, t_y *y, double camera)
{

		x->ray_dir_x = vars->dirX + vars->planeX * camera;
		y->ray_dir_y = vars->dirY + vars->planeY * camera;	
		x->map_x = (int) vars->posX;
    y->map_y = (int) vars->posY;
    x->dlt_dist_x = (x->ray_dir_x == 0) ? 1e30 : abs_double(1 / x->ray_dir_x);
    y->dlt_dist_y = (y->ray_dir_y == 0) ? 1e30 : abs_double(1 / y->ray_dir_y);
}
void  first_step(t_vars *vars, t_x *x, t_y *y)
{
  if(x->ray_dir_x < 0)
  {
    x->step_x = -1;
    x->side_dist_x = (vars->posX - x->map_x) * x->dlt_dist_x;
  }
  else
  {
    x->step_x = 1;
    x->side_dist_x = (x->map_x + 1.0 - vars->posX) * x->dlt_dist_x;
  }
  if(y->ray_dir_y < 0)
  {
    y->step_y = -1;
    y->side_dist_y = (vars->posY - y->map_y) * y->dlt_dist_y;
  }
  else
  {
    y->step_y = 1;
    y->side_dist_y = (y->map_y + 1.0 - vars->posY) * y->dlt_dist_y;
  }
}
int calc_dda(t_x *x, t_y *y)
{
  int hit;
  int side;
  double  per_wall_dist;

  hit = 0;
  while(hit == 0)
  {
    if(x->side_dist_x < y->side_dist_y)
    {
      x->side_dist_x += x->dlt_dist_x;
      x->map_x += x->step_x;
      side = 0;
    }
    else
    {
      y->side_dist_y += y->dlt_dist_y;
      y->map_y += y->step_y;
      side = 1;
    }
    if(worldMap[x->map_x][y->map_y] > 0)
      hit = 1;
  }
  if(side == 0)
    per_wall_dist = (x->side_dist_x - x->dlt_dist_x);
  else
    per_wall_dist = (y->side_dist_y - y->dlt_dist_y);
  return ((int)(WIN_HEIGHT / per_wall_dist));
}

void  drawing(t_vars *vars, int i, int line_height)
{
  int draw_start;
  int draw_end;
  
  draw_start = -line_height / 2 + WIN_HEIGHT / 2;
  if(draw_start < 0)
    draw_start = 0;
  draw_end = line_height / 2 + WIN_HEIGHT / 2;
  if(draw_end >= WIN_HEIGHT)
    draw_end = WIN_HEIGHT - 1;
	for(int j = draw_start; j < draw_end; j++)
		  mlx_pixel_put(vars->mlx, vars->win, i, j, 255);

}

void	calc(t_vars *vars)
{
	int		i;
	double	camera;
  t_x   x;
  t_y   y;

  mlx_clear_window(vars->mlx, vars->win);
	i = 0;
	while (i < WIN_WIDTH)
	{
		camera = 2 * i / (double)WIN_WIDTH - 1;
    set_value(vars, &x, &y, camera);
    first_step(vars, &x, &y);
    drawing(vars, i, calc_dda(&x, &y));
		i++;
	}
	return ;
}

int	main(void)
{
	t_vars vars;

  //init vars
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH,WIN_HEIGHT, "cub3d!");
  vars.dirX = -1;
  vars.dirY = 0;
  vars.posX = 22;
  vars.posY = 12;
  vars.planeX = 0;
  vars.planeY = 0.66;

  vars.sample.img = mlx_xpm_file_to_image(vars.mlx, "./images/redbrick.xpm", &(vars.sample.img_width), &(vars.sample.img_height));
  vars.sample.addr = mlx_get_data_addr(vars.sample.img, &(vars.sample.bits_per_pixel), &(vars.sample.size_len), &(vars.sample.endian));
  mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
  //mlx_hook(vars.win, 17, 1L<<0, keypress, &vars);
  calc(&vars);
	mlx_loop(vars.mlx);
}
