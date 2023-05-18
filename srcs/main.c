#include "../includes/cub3d.h"
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


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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


void	calc(t_vars *vars)
{
	int		i;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;

  mlx_clear_window(vars->mlx, vars->win);
	i = 0;
	while (i < WIN_WIDTH)
	{
		cameraX = 2 * i / (double)WIN_WIDTH - 1;
		rayDirX = vars->dirX + vars->planeX * cameraX;
		rayDirY = vars->dirY + vars->planeY * cameraX;	
		i++;
		int mapX = (int) vars->posX;
    int mapY = (int) vars->posY;

      double sideDistX;
      double sideDistY;

      double deltaDistX = (rayDirX == 0) ? 1e30 : abs_double(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : abs_double(1 / rayDirY);
      double perpWallDist;
      int stepX;
      int stepY;

      int hit = 0;
      int side;
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (vars->posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - vars->posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (vars->posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - vars->posY) * deltaDistY;
      }
    
      while(hit == 0)
      {
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
      if(drawEnd >= WIN_HEIGHT) drawEnd = WIN_HEIGHT - 1;
	  for(int j = drawStart; j < drawEnd; j++)
	  {
		  mlx_pixel_put(vars->mlx, vars->win, i, j, 255);
	  }
	}
	return ;
}

int	main(void)
{
	t_vars vars;
	t_data	img;

  //init vars
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH,WIN_HEIGHT, "Hello world!");
  vars.dirX = -1;
  vars.dirY = 0;
  vars.posX = 22;
  vars.posY = 12;
  vars.planeX = 0;
  vars.planeY = 0.66;

	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
  mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
  //mlx_hook(vars.win, 17, 1L<<0, keypress, &vars);
  calc(&vars);
	mlx_loop(vars.mlx);
}
