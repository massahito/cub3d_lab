#include "cub3d.h"

char	*delete_line_break(char *line)
{
	char	*new;
	size_t	len;

	if (!line)
		return (NULL);
	len = strlen(line);
	if (line[len - 1] != '\n')
		return (line);
	new = strndup(line, len - 1);
	if (!new)
		malloc_err();
	free(line);
	return (new);
}

static char	*delete_line_space(char *line)
{
	size_t	i;
	char	*return_value;

	i = 0;
	if (!line)
		return (NULL);
	while (ft_isspace(line[i]))
		i++;
	return_value = ft_strdup(&line[i]);
	free(line);
	return (return_value);
}

static char	*delete_line_back_space(char *line)
{
	size_t	i;
	char	*return_value;

	if (!line)
		return (NULL);
	i = ft_strlen(line) - 1;
	while (ft_isspace(line[i]))
		i--;
	return_value = ft_substr(line, 0, i + 1);
	free(line);
	return (return_value);
}

char	*delete_parts_not_needed_line(char *line)
{
	line = delete_line_space(line);
	line = delete_line_break(line);
	line = delete_line_back_space(line);
	return (line);
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
