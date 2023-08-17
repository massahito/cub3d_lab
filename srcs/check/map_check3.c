/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:41:22 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:41:23 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	whether_possible_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
		{
			error("Invalid character: ", &line[i], NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

int	whether_player_is_right_or_not(char *line, size_t *player_count)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			*player_count += 1;
		i++;
	}
	return (0);
}

int	apply_list(t_map_list *map_list, int (*pfunc)(char *))
{
	if (pfunc == NULL)
		return (0);
	while (map_list)
	{
		if (pfunc(map_list->line))
			return (1);
		map_list = map_list->next;
	}
	return (0);
}

int	apply_list2(t_map_list *map_list, size_t *count, int (*pfunc)(char *,
			size_t *))
{
	if (pfunc == NULL)
		return (0);
	while (map_list)
	{
		if (pfunc(map_list->line, count))
			return (1);
		map_list = map_list->next;
	}
	return (0);
}

size_t	max_line_size(t_map_list *map_list)
{
	size_t	max;
	size_t	tmp;

	max = strlen(map_list->line);
	while (map_list)
	{
		tmp = strlen(map_list->line);
		if (max < tmp)
			max = tmp;
		map_list = map_list->next;
	}
	return (max);
}
