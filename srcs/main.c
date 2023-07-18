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
t_data calc_dda(t_x *x, t_y *y)
{
  int     hit;
  int     side;
  t_data  data;

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
  data.side = side;
  if(side == 0)
    data.wall_dist = (x->side_dist_x - x->dlt_dist_x);
  else
    data.wall_dist = (y->side_dist_y - y->dlt_dist_y);
  data.wall_height  = WIN_HEIGHT / data.wall_dist;
  return (data);
}

void  drawing(t_vars *vars, int i, t_data data)
{
  int     draw_start;
  int     draw_end;
  double  tex_pos;
  
  draw_start = -1 * data.wall_height / 2 + WIN_HEIGHT / 2;
  if(draw_start < 0)
    draw_start = 0;
  draw_end = data.wall_height / 2 + WIN_HEIGHT / 2;
  if(draw_end >= WIN_HEIGHT)
    draw_end = WIN_HEIGHT - 1;
  tex_pos = (draw_start - WIN_HEIGHT / 2 + data.wall_dist / 2) * data.step;
  for(int j = 0; j < draw_start; j++)
    mlx_pixel_put(vars->mlx, vars->win, i, j, 0xfc5454);
	for(int j = draw_start; j < draw_end; j++)
  	{
   		 data.tex_y = (int) tex_pos & (vars->sample.img_height - 1);
   		 tex_pos += data.step;
		mlx_pixel_put(vars->mlx, vars->win, i, j, *(unsigned int *)(vars->sample.addr + data.tex_y * vars->sample.size_len + data.tex_x * (vars->sample.bits_per_pixel / 8)));
  }
  for (int j = draw_end; j < WIN_HEIGHT; j++)
    mlx_pixel_put(vars->mlx, vars->win, i, j, 0x707070);
}

void  set_data(t_data *data, t_vars *vars, t_x x, t_y y)
{
  double wall;

  if (data->side == 0)
  {
    wall = vars->posY + data->wall_dist * y.ray_dir_y;
	if (x.ray_dir_x < 0)
		vars->sample = vars->wall[0];
	else
		vars->sample = vars->wall[1];
  }
  else
  {
    wall = vars->posX + data->wall_dist * x.ray_dir_x;
	if (y.ray_dir_y < 0)
		vars->sample = vars->wall[2];
	else
		vars->sample = vars->wall[3];
  }
  wall = wall - floor(wall);
  data->tex_x = (int)(wall * (double)(vars->sample.img_width));
  if (data->side == 0 && x.ray_dir_x > 0)
      data->tex_x = vars->sample.img_width - data->tex_x - 1; 
  else if (data->side == 1 && y.ray_dir_y < 0)
      data->tex_x = vars->sample.img_width - data->tex_x - 1; 
  data->step = (1.0 * vars->sample.img_width) / data->wall_height;
}

void	calc(t_vars *vars)
{
	int     i;
	double	camera;
  t_x     x;
  t_y     y;
  t_data  data;
	i = 0;
	while (i < WIN_WIDTH)
	{
		camera = 2 * i / (double)WIN_WIDTH - 1;
    set_value(vars, &x, &y, camera);
    first_step(vars, &x, &y);
    data = calc_dda(&x, &y);
    set_data(&data, vars, x, y);
    drawing(vars, i, data);
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

  //iamge download
  void	*img0 = mlx_xpm_file_to_image(vars.mlx, "./images/redbrick.xpm", &(vars.wall[0].img_width), &(vars.wall[0].img_height));
  vars.wall[0].addr = mlx_get_data_addr(img0, &(vars.wall[0].bits_per_pixel), &(vars.wall[0].size_len), &(vars.wall[0].endian));
  void	*img1 = mlx_xpm_file_to_image(vars.mlx, "./images/bluestone.xpm", &(vars.wall[1].img_width), &(vars.wall[1].img_height));
  vars.wall[1].addr = mlx_get_data_addr(img1, &(vars.wall[1].bits_per_pixel), &(vars.wall[1].size_len), &(vars.wall[1].endian));
  void	*img2 = mlx_xpm_file_to_image(vars.mlx, "./images/colorstone.xpm", &(vars.wall[2].img_width), &(vars.wall[2].img_height));
  vars.wall[2].addr = mlx_get_data_addr(img2, &(vars.wall[2].bits_per_pixel), &(vars.wall[2].size_len), &(vars.wall[2].endian));
  void	*img3 = mlx_xpm_file_to_image(vars.mlx, "./images/greystone.xpm", &(vars.wall[3].img_width), &(vars.wall[3].img_height));
  vars.wall[3].addr = mlx_get_data_addr(img3, &(vars.wall[3].bits_per_pixel), &(vars.wall[3].size_len), &(vars.wall[3].endian));

  mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
  //mlx_hook(vars.win, 17, 1L<<0, keypress, &vars);
  calc(&vars);
	mlx_loop(vars.mlx);
}
