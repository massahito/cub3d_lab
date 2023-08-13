#include "cub3d.h"

bool	is_no_str(char *line)
{
	while (isspace(*line))
		line++;
	if (strncmp(line, "", 1) == 0 || strncmp(line, "\n", 1) == 0)
		return (true);
	return (false);
}

void	delete_map_space(t_map_list **map_list)
{
	t_map_list	*tmp;
	t_map_list	*last;
	char		*line;

	last = map_last(*map_list);
	while (1)
	{
		last = map_last(*map_list);
		tmp = last->prev;
		line = last->line;
		if (is_no_str(line))
		{
			free_map_clear(last);
			tmp->next = NULL;
		}
		else
			break ;
	}
}

char	*delete_line_break(char *line)
{
	char	*new;
	size_t	len;

	len = strlen(line);
	if (line[len - 1] != '\n')
		return (line);
	new = strndup(line, len - 1);
	if (!new)
		malloc_err();
	free(line);
	return (new);
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
