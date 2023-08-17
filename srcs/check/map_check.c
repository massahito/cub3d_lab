/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:41:17 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:41:18 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	what_next_character(int i, int j, char **map, bool *flag)
{
	char	c;

	c = C;
	if (*flag == true)
		return (false);
	else if (map[i][j] == c)
	{
		*flag = true;
		return (false);
	}
	else if (map[i][j] == '0')
	{
		map[i][j] = '!';
		return (true);
	}
	return (false);
}

static void	surrounded_walls(int i, int j, char **map, bool *flag)
{
	if (what_next_character(i, j - 1, map, flag))
		surrounded_walls(i, j - 1, map, flag);
	if (what_next_character(i - 1, j, map, flag))
		surrounded_walls(i - 1, j, map, flag);
	if (what_next_character(i, j + 1, map, flag))
		surrounded_walls(i, j + 1, map, flag);
	if (what_next_character(i + 1, j, map, flag))
		surrounded_walls(i + 1, j, map, flag);
}

static void	get_player_position(char **map, int *i, int *j)
{
	int	k;
	int	l;

	k = 0;
	while (map[k])
	{
		l = 0;
		while (map[k][l])
		{
			if (map[k][l] == 'N' || map[k][l] == 'S' || map[k][l] == 'E'
				|| map[k][l] == 'W')
			{
				*i = k;
				*j = l;
				return ;
			}
			l++;
		}
		k++;
	}
}

static int	dfs(char **map)
{
	bool	flag;
	int		i;
	int		j;

	flag = false;
	get_player_position(map, &i, &j);
	surrounded_walls(i, j, map, &flag);
	if (flag == true)
	{
		map_free(map);
		error("No walls around", NULL, NULL);
		return (1);
	}
	map_free(map);
	return (0);
}

int	map_check(t_map_list **map_list)
{
	size_t	player_count;
	char	**dfs_map;

	player_count = 0;
	if (apply_list(*map_list, whether_possible_characters))
		return (1);
	apply_list2(*map_list, &player_count, whether_player_is_right_or_not);
	if (player_count != 1)
	{
		error("player count is not 1", NULL, NULL);
		return (1);
	}
	make_x_map(*map_list);
	surround(map_list);
	dfs_map = make_map(*map_list);
	if (dfs(dfs_map))
		return (1);
	return (0);
}
