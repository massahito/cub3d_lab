#include "cub3d.h"

static t_texture_name	*new_texture_name(void)
{
	t_texture_name	*texture_name;

	texture_name = malloc(sizeof(t_texture_name));
	if (!texture_name)
		malloc_err();
	texture_name->north = NULL;
	texture_name->south = NULL;
	texture_name->west = NULL;
	texture_name->east = NULL;
	texture_name->floor = NULL;
	texture_name->ceiling = NULL;
	return (texture_name);
}

void	free_azimuths(t_texture_name *texture_name)
{
	if (texture_name)
	{
		if (texture_name->north)
			free(texture_name->north);
		if (texture_name->south)
			free(texture_name->south);
		if (texture_name->west)
			free(texture_name->west);
		if (texture_name->east)
			free(texture_name->east);
		if (texture_name->floor)
			free(texture_name->floor);
		if (texture_name->ceiling)
			free(texture_name->ceiling);
		free(texture_name);
	}
}

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
		map[i] = strdup(tmp->line);
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

int	fill_in_one_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == C)
			line[i] = '1';
		i++;
	}
	return (0);
}

void	palyer_direction_check(t_texture_name *texture_name,
		t_map_list *map_list)
{
	int			i;
	int			k;
	char		c;
	t_map_list	*tmp;

	i = 0;
	k = 0;
	tmp = map_list;
	(void)texture_name;
	while (tmp)
	{
		while (tmp->line[i])
		{
			if (tmp->line[i] != '0' && tmp->line[i] != '1')
			{
				texture_name->pos_x = i;
				texture_name->pos_y = k;
				c = tmp->line[i];
			}
			i++;
		}
		k++;
		tmp = tmp->next;
		i = 0;
	}
	if (c == 'N')
		texture_name->direction = North;
	if (c == 'S')
		texture_name->direction = South;
	if (c == 'W')
		texture_name->direction = West;
	if (c == 'E')
		texture_name->direction = East;
}

void					prints(t_texture_name *texture_name,
							t_map_list *map_list);
void	read_cub_file(char *argv, t_texture_name **texture_name,
		t_map_list **map_list)
{
	int	file_fd;

	*texture_name = new_texture_name();
	if (!*texture_name)
		malloc_err();
	file_fd = open(argv, O_RDONLY);
	if (file_fd == -1)
	{
		error("cub file open error", NULL, NULL, EXIT_FAILURE);
		free_azimuths(*texture_name);
		exit(EXIT_FAILURE);
	}
	if (read_azimuths(texture_name, file_fd))
	{
		close(file_fd);
		free_azimuths(*texture_name);
		exit(EXIT_FAILURE);
	}
	if (read_fc_color(texture_name, file_fd))
	{
		close(file_fd);
		free_azimuths(*texture_name);
		exit(EXIT_FAILURE);
	}
	if (read_map(map_list, file_fd))
	{
		close(file_fd);
		free_azimuths(*texture_name);
		free_map_list(*map_list);
		exit(EXIT_FAILURE);
	}
	if (map_check(map_list))
	{
		close(file_fd);
		free_azimuths(*texture_name);
		free_map_list(*map_list);
		exit(EXIT_FAILURE);
	}
	apply_list(*map_list, fill_in_one_line);
	palyer_direction_check(*texture_name, *map_list);
	// prints(*texture_name,*map_list);
	close(file_fd);
	// free_azimuths(*texture_name);
	// free_map_list(*map_list);
}

/**
 * どこに何が入ってるかチェックするための関数
 */
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		// printf("%s", map[i]);
		printf("%s\n", map[i]);
		i++;
	}
	fflush(stdout);
	map_free(map);
}

void	prints(t_texture_name *texture_name, t_map_list *map_list)
{
	// printf("NO : %s", texture_name->north);
	// printf("SO : %s", texture_name->south);
	// printf("WE : %s", texture_name->west);
	// printf("EA : %s", texture_name->east);
	// printf("F : %s", texture_name->floor);
	// printf("C : %s", texture_name->ceiling);
	printf("NO : %s\n", texture_name->north);
	printf("SO : %s\n", texture_name->south);
	printf("WE : %s\n", texture_name->west);
	printf("EA : %s\n", texture_name->east);
	printf("F : %s\n", texture_name->floor);
	printf("C : %s\n", texture_name->ceiling);
	print_map(make_map(map_list));
}