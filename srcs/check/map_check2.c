#include "cub3d.h"

static void	move_line(char *line, char *newline)
{
	while (*line)
	{
		if (isspace(*line) == 0)
			*newline = *line;
		line++;
		newline++;
	}
}

static void	remake_line(t_map_list *map_list, size_t max_size)
{
	char	*newline;

	newline = malloc(sizeof(char) * (max_size + 1));
	if (!newline)
		malloc_err();
	memset(newline, C, max_size);
	newline[max_size] = '\0';
	move_line(map_list->line, newline);
	free(map_list->line);
	map_list->line = newline;
}

void	make_x_map(t_map_list *map_list)
{
	size_t	max_size;

	max_size = max_line_size(map_list);
	while (map_list)
	{
		remake_line(map_list, max_size);
		map_list = map_list->next;
	}
}

static char	*make_x_line(char *line, size_t size, char c)
{
	char	*newline;
	size_t	i;

	newline = malloc(sizeof(char) * (size + 1));
	if (!newline)
		malloc_err();
	memset(newline, c, size);
	newline[size] = '\0';
	if (line == NULL)
		return (newline);
	i = 0;
	newline++;
	while (line[i])
	{
		newline[i] = line[i];
		i++;
	}
	free(line);
	return (newline - 1);
}

void	surround(t_map_list **map_list)
{
	size_t		size;
	t_map_list	*new;
	t_map_list	*list;

	size = strlen((*map_list)->line) + 2;
	new = new_map_list(make_x_line(NULL, size, C));
	new->next = *map_list;
	(*map_list)->prev = new;
	*map_list = new;
	list = new->next;
	while (list)
	{
		list->line = make_x_line(list->line, size, C);
		list = list->next;
	}
	list = map_last(*map_list);
	new = new_map_list(make_x_line(NULL, size, C));
	list->next = new;
	new->prev = list;
}
