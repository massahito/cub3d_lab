/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:17 by marai             #+#    #+#             */
/*   Updated: 2023/08/17 13:48:19 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_vars			vars;
	t_texture_name	*texture_name;
	t_map_list		*map_list;

	texture_name = NULL;
	map_list = NULL;
	if (argc != 2)
	{
		error("Invalid argument", NULL, NULL);
		exit(EXIT_FAILURE);
	}
	if (check_file(argv[1]))
		exit(EXIT_FAILURE);
	read_cub_file(argv[1], &texture_name, &map_list);
	vars.mlx = mlx_init();
	add_vars(&vars, texture_name, map_list);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d!");
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 17, 1L << 2, mlx_destroy, &vars);
	calc(&vars);
	mlx_loop(vars.mlx);
}
