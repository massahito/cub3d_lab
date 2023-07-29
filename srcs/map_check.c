#include "cub3d.h"

int whether_possible_characters(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if(line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
        {
            error("Error", "Invalid character: ", &line[i], EXIT_FAILURE);
            return 1;
        }
        i++;
    }
    return 0;
}

int whether_player_is_right_or_not(char *line, size_t *player_count)
{
    int i;

    i = 0;
    while(line[i])
    {
        if(line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
            *player_count += 1;
        i++;
    }
    return 0;
}

int apply_list(t_map_list *map_list,int (* pfunc)(char *))
{
    if(pfunc == NULL)
        return 0;
    while(map_list)
    {
        if(pfunc(map_list->line))
            return 1;
        map_list = map_list->next;
    }
    return 0;
}

int apply_list2(t_map_list *map_list, size_t *count, int (* pfunc)(char *,size_t *))
{
    if(pfunc == NULL)
        return 0;
    while(map_list)
    {
        if(pfunc(map_list->line, count))
            return 1;
        map_list = map_list->next;
    }
    return 0;
}
size_t max_line_size(t_map_list *map_list)
{
    size_t max;
    size_t tmp;

    max = strlen(map_list->line);
    while (map_list)
    {
        tmp = strlen(map_list->line);
        if(max < tmp)
            max = tmp;
        
        map_list = map_list->next;
    }
    return max;
}

void move_line(char *line, char *newline)
{
    while(*line)
    {
        if(isspace(*line) == 0)
            *newline = *line;
        line++;
        newline++;
    }
}

void remake_line(t_map_list *map_list, size_t max_size)
{
    char *newline;

    newline = malloc(sizeof(char) * (max_size + 1));
    if(!newline)
        MALLOC_ERR;
    memset(newline, C, max_size);
    newline[max_size] = '\0';
    move_line(map_list->line, newline);
    free(map_list->line);
    map_list->line = newline;
}

void make_x_map(t_map_list *map_list)
{
    size_t max_size;

    max_size = max_line_size(map_list);
    while(map_list)
    {
        remake_line(map_list, max_size);
        map_list = map_list->next;
    }
}

char *make_x_line(char *line, size_t size,char c)
{
    char *newline;
    size_t i;

    newline = malloc(sizeof(char) * (size + 1));
    if(!newline)
        MALLOC_ERR;
    memset(newline, c, size);
    newline[size] = '\0';
    if(line == NULL)
        return newline;
    i = 0;
    newline++;
    while(line[i])
    {
        newline[i] = line[i];
        i++;
    }
    free(line);
    return newline -1;
}

void surround(t_map_list **map_list)
{
    size_t size;
    t_map_list *new;
    t_map_list *list;


    size = strlen((*map_list)->line) + 2;
    new = new_map_list(make_x_line(NULL, size, C));
    new->next = *map_list;
    (*map_list)->prev = new;
    *map_list = new;
    list = new->next;
    while(list)
    {
        list->line = make_x_line(list->line, size, C);
        list = list->next;
    }
    list = map_last(*map_list);
    new = new_map_list(make_x_line(NULL, size, C));
    list->next = new;
    new->prev = list;
}

static bool	what_next_character(int i, int j, char **map,bool *flag)
{
    char c;

    c = C;
    if(*flag == true)
        return false;
	else if (map[i][j] == c)
	{
        *flag = true;
        return false;
	}
	else if (map[i][j] == '0')
	{
		map[i][j] = '!';
		return (true);
	}
	return (false);
}

void	surrounded_walls(int i, int j, char **map, bool *flag)
{
	if (what_next_character(i, j - 1, map, flag))
		surrounded_walls(i, j - 1, map, flag);
	if (what_next_character(i - 1, j, map, flag))
		surrounded_walls(i - 1, j, map, flag);
	if (what_next_character(i, j + 1, map, flag))
		surrounded_walls(i, j + 1, map, flag);
	if (what_next_character(i + 1, j, map, flag))
		surrounded_walls(i + 1, j, map, flag);
}

void get_player_position(char **map, int *i, int *j)
{
    int k;
    int l;

    k = 0;
    while(map[k])
    {
        l = 0;
        while(map[k][l])
        {
            if(map[k][l] == 'N' || map[k][l] == 'S' || map[k][l] == 'E' || map[k][l] == 'W')
            {
                *i = k;
                *j = l;
                return ;
            }
            l++;
        }
        k++;
    }
}

int dfs(char **map)
{
    bool flag;
    int i;
    int j;

    flag = false;
    get_player_position(map, &i, &j);
    surrounded_walls(i,j, map, &flag);
    if(flag == true)
    {
        map_free(map);
        error("Error: ", "No walls around", NULL,2);
        return 1;
    }
    map_free(map);
    return 0;
}

int map_check(t_map_list **map_list)
{
    size_t player_count = 0;
    char **dfs_map;

    if(apply_list(*map_list, whether_possible_characters))
        return 1;
    apply_list2(*map_list, &player_count, whether_player_is_right_or_not);
    if(player_count != 1)
    {
        error("Error: ", "player count is not 1", NULL, 2);
        return 1;
    }
    make_x_map(*map_list);
    surround(map_list);
    dfs_map = make_map(*map_list);
    if(dfs(dfs_map))
        return 1;
    return 0;
}
