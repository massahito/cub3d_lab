#include "cub3d.h"

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
