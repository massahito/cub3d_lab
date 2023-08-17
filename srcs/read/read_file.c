/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:42:02 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:42:03 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_texture_direction(t_texture_name *texture_name, char c)
{
	if (c == 'N')
		texture_name->direction = North;
	if (c == 'S')
		texture_name->direction = South;
	if (c == 'W')
		texture_name->direction = West;
	if (c == 'E')
		texture_name->direction = East;
}

static void	player_direction_check(t_texture_name *texture_name,
		t_map_list *map_list, int i, int k)
{
	char		c;
	t_map_list	*tmp;

	tmp = map_list;
	while (tmp)
	{
		while (tmp->line[i])
		{
			if (tmp->line[i] != '0' && tmp->line[i] != '1')
			{
				texture_name->pos_x = i;
				texture_name->pos_y = k;
				c = tmp->line[i];
				tmp->line[i] = '0';
			}
			i++;
		}
		k++;
		tmp = tmp->next;
		i = 0;
	}
	add_texture_direction(texture_name, c);
}

void	read_cub_file(char *argv, t_texture_name **texture_name,
		t_map_list **map_list)
{
	int	file_fd;

	*texture_name = new_texture_name();
	if (!*texture_name)
		malloc_err();
	file_fd = open(argv, O_RDONLY);
	if (file_fd == -1)
		read_err("cub file open error", -1, NULL);
	if (read_azimuths_floor_ceil(texture_name, file_fd))
		read_err(NULL, file_fd, texture_name);
	if (read_map(map_list, file_fd))
		read_err(NULL, file_fd, texture_name);
	if (map_check(map_list))
		read_err(NULL, file_fd, texture_name);
	apply_list(*map_list, fill_in_one_line);
	player_direction_check(*texture_name, *map_list, 0, 0);
	close(file_fd);
}
