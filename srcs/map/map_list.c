/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:41:29 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:41:30 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_list	*map_last(t_map_list *map_list)
{
	t_map_list	*tmp;

	tmp = map_list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_map_list	*new_map_list(char *line)
{
	t_map_list	*new;

	new = (t_map_list *)malloc(sizeof(t_map_list));
	if (!new)
		malloc_err();
	new->line = line;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_map_list(t_map_list **map_list, char *line)
{
	t_map_list	*new;
	t_map_list	*tmp;

	new = new_map_list(line);
	if (*map_list == NULL)
	{
		*map_list = new;
		return ;
	}
	tmp = map_last(*map_list);
	tmp->next = new;
	new->prev = tmp;
}

size_t	map_list_size(t_map_list *map_list)
{
	size_t		size;
	t_map_list	*tmp;

	size = 0;
	tmp = map_list;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
