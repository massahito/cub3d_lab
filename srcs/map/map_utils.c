/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:41:41 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 14:02:18 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_free(char **map)
{
	size_t	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

char	**make_map(t_map_list *map_list)
{
	char		**map;
	t_map_list	*tmp;
	int			i;

	tmp = map_list;
	map = (char **)malloc(sizeof(char *) * (map_list_size(map_list) + 1));
	if (!map)
		malloc_err();
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->line);
		if (map[i] == NULL)
		{
			map_free(map);
			malloc_err();
		}
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
