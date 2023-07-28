#include "cub.h"

typedef struct s_map_list t_map_list;
struct s_map_list
{
    char *line;
    t_map_list *next;
    t_map_list *prev;
};

t_map_list *map_last(t_map_list *map_list)
{
    t_map_list *tmp;

    tmp = map_list;
    while(tmp->next)
        tmp = tmp->next;
    return (tmp);
}


t_map_list  *new_map_list(char *line)
{
    t_map_list *new;

    new = (t_map_list *)malloc(sizeof(t_map_list));
    if(!new)
        ERR;
    new->line = line;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

void add_map_list(t_map_list **map_list, char *line)
{
    t_map_list *new;
    t_map_list *tmp;

    new = new_map_list(line);
    if(*map_list == NULL)
    {
        *map_list = new;
        return;
    }
    tmp = map_last(*map_list);
    tmp->next = new;
    new->prev = tmp;    
}

size_t map_list_size(t_map_list *map_list)
{
    size_t size;
    t_map_list *tmp;

    size = 0;
    tmp = map_list;
    while(tmp)
    {
        size++;
        tmp = tmp->next;
    }
    return (size);
}

char **make_map(t_map_list *map_list)
{
    char **map;
    t_map_list *tmp;
    int i;

    tmp = map_list;
    map = (char **)malloc(sizeof(char *) * (map_list_size(map_list) + 1));
    if(!map)
        ERR;
    i = 0;
    while(tmp)
    {
        map[i] = tmp->line;
        tmp = tmp->next;
        i++;
    }
    map[i] = NULL;
    return (map);
}


void print_list(t_map_list *map_list)
{
    t_map_list *tmp;

    tmp = map_list;
    printf("start\n");
    while(tmp)
    {
        printf("%s\n", tmp->line);
        tmp = tmp->next;
    }
    printf("end\n");
}

void print_map(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        printf("%s", map[i]);
        i++;
    }
}

void free_map_clear(t_map_list *map_list)
{
    if(map_list)
    {
        if(map_list->line)
            free(map_list->line);
        map_list->next = NULL;
        map_list->prev = NULL;
        free(map_list);
    }
}

void delete_map_space(t_map_list **map_list)
{
    t_map_list *tmp;
    t_map_list *last;
    char *line;

    last = map_last(*map_list);
    while(1)
    {
        last = map_last(*map_list);
        tmp = last->prev;
        line = last->line;
        while(isspace(*line))
        {
            line++;
        }
        if(strncmp(line, "", 1) == 0 || strncmp(line, "\n", 1) == 0)
        {
            free_map_clear(last);
            tmp->next = NULL;
        }
        else
            break;
    }


}

void read_map(int fd)
{
    t_map_list *map_list;
    char *line;
    size_t max_len;
    char **map;

    map_list = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if(line == NULL)
            ERR;
        else if(strcmp(line, "") == 0 || strcmp(line, "\n") == 0)
        {
            free(line);
            continue;
        }
        else
            break;
    }
    map_list = new_map_list(line);
    max_len = strlen(line);
    free(line);
    while(1)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        add_map_list(&map_list, line);
        if(max_len < strlen(line))
            max_len = strlen(line);
    }
    delete_map_space(&map_list);
    map = make_map(map_list);

    print_map(map);
}