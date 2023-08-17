/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:42:07 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:42:07 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_no_str(char *line)
{
	while (isspace(*line))
		line++;
	if (strncmp(line, "", 1) == 0 || strncmp(line, "\n", 1) == 0)
		return (true);
	return (false);
}

static char	*read_map_utils(int fd, char *line)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (NULL);
		else if (strcmp(line, "") == 0 || strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		else
			break ;
	}
	return (line);
}

int	read_map(t_map_list **map_list, int fd)
{
	char	*line;

	line = read_map_utils(fd, NULL);
	if (line == NULL)
		return (error("Map not found", NULL, NULL));
	add_map_list(map_list, delete_line_break(line));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_map_list(map_list, delete_line_break(line));
	}
	delete_map_space(map_list);
	return (0);
}
