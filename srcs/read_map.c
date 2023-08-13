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

void	print_list(t_map_list *map_list)
{
	t_map_list	*tmp;

	tmp = map_list;
	printf("start\n");
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	printf("end\n");
}

void	free_map_clear(t_map_list *map_list)
{
	if (map_list)
	{
		if (map_list->line)
			free(map_list->line);
		map_list->next = NULL;
		map_list->prev = NULL;
		free(map_list);
	}
}

void	free_map_list(t_map_list *map_list)
{
	t_map_list	*tmp;

	while (map_list)
	{
		tmp = map_list->next;
		free_map_clear(map_list);
		map_list = tmp;
	}
}

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

int	read_map(t_map_list **map_list, int fd)
{
	char *line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			return (error("Map not found", NULL, NULL, 2));
		}
		else if (strcmp(line, "") == 0 || strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		else
			break ;
	}
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
