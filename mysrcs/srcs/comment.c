#include "cub.h"

typedef enum azimuth{
  North,
  South,
  West,
  East,
  AZIMUTH_Vary,
  AZIMUTH_No,
} e_azimuth;

void error(void)
{
    write(1,"Err\n",4);
    exit(1);
}
// /**
//  * attention
//  * Except for the map content, each type of element can be separated by one or more empty line(s).
// */
// static void error(char *str);

typedef struct s_texture_name
{
    char   *north;
    char   *south;
    char   *west;
    char   *east;
    char   *floor;
    char   *ceiling;
}			t_texture_name;

// /**
//  * Check if the file ends with *.cub
// */
void check_file_name(char *str)
{
    int i;

    i = 0;
    if(!str  || !*str)
        ERR;
    while(str[i])
        i++;
    if(str[i - 4] == '.' && str[i - 3] == 'c' && str[i - 2] == 'u' && str[i - 1] == 'b')
            return ;
    ERR;
}

// /**
//  * get_next_line
// */

// /**
//  * North or not. 
// */

// char *get_texture_name(char *str)
// {
//     int i;
//     char *texture_name;

//     i = 0;
//     if(!str  || !*str)
//     {
//         error("Error   File name is empty.\n");
//         return ;
//     }
//     while(isspace(*str))
//         str++;
//     texture_name = strdup(str);        
//     return (texture_name);
// }

/**
 * South or not.
*/

/**
 * West or not.
*/

/**
 * East or not.
*/

/**
 * gnl
 * Azimuth or not.
 * Otherwise, error.
*/

/**
 * texture.
 * Change to mlx.
*/

/**
 * Floor or not.
*/

/**
 * Ceiling or not.
*/

/**
 * gnl
 * Floor or Ceiling or not.
 * Otherwise, error.
*/

/**
 * Floor and Ceiling.
 * Change to mlx.
*/

/**
 * Creating a list of maps
 * gnl 
 * linear list
 * per line
*/

/**
 * The map must be composed of only 6 possible characters: 0 for an empty space,
 * 1 for a wall, and N,S,E or W for the player’s start position and spawning
 * orientation.
*/

/**
 * The map must be closed/surrounded by walls, if not the program must return
 * an error.
*/

/**
 * Change map to char **.
*/

/**
 * 
*/
e_azimuth which_azimuth(char *line)
{
    e_azimuth re;

    while(isspace(*line))
        line++;
    if(strncmp(line,"NO",2) == 0)
        re = North;
    else if(strncmp(line,"SO",2) == 0)
        re = South;
    else if(strncmp(line,"WE",2) == 0)
        re = West;
    else if(strncmp(line,"EA",2) == 0)
        re = East;
    else if(strncmp(line, "\0",1) == 0)
        re = AZIMUTH_No;
    else
        re = AZIMUTH_Vary;
    return re;
}

t_texture_name *new_texture_name(void)
{
    t_texture_name *texture_name;

    texture_name = malloc(sizeof(t_texture_name));
    if(!texture_name)
        ERR;
    texture_name->north = NULL;
    texture_name->south = NULL;
    texture_name->west = NULL;
    texture_name->east = NULL;
    texture_name->floor = NULL;
    texture_name->ceiling = NULL;
    return texture_name;
}

void get_azimuth_texture_name(char *line, e_azimuth azimuth, t_texture_name **azimuths)
{
    char *texture_name;

    while(isspace(*line))
        line++;
    line += 2;
    while(isspace(*line))
        line++;
    texture_name = strdup(line);
    if(!texture_name)
        ERR;
    if(azimuth == North)
        (*azimuths)->north = texture_name;
    else if(azimuth == South)
        (*azimuths)->south = texture_name;
    else if(azimuth == West)
        (*azimuths)->west = texture_name;
    else if(azimuth == East)
        (*azimuths)->east = texture_name;
}

void read_azimuths(t_texture_name **texture_name, int fd)
{
    e_azimuth azimuth;
    char *line;
    int n;

    n = 0;
    (void)texture_name;
    while(1)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        azimuth = which_azimuth(line);
        if(azimuth ==  AZIMUTH_Vary)
            ERR;
        else if(azimuth == AZIMUTH_No)
        {
            free(line);
            continue;
        }
        else
        {
            n += 1;
            get_azimuth_texture_name(line, azimuth, texture_name);
        }
        free(line);
        if(n == 4)
            break;
    }
}

typedef enum floor_or_ceiling{
    Floor,
    Ceiling,
    FC_Vary,
    FC_No,
} e_floor_or_ceiling;

e_floor_or_ceiling which_fc(char *line)
{
    e_floor_or_ceiling re;

    while(isspace(*line))
        line++;
    if(strncmp(line,"F",1) == 0)
        re = Floor;
    else if(strncmp(line,"C",1) == 0)
        re = Ceiling;
    else if(strncmp(line, "\0",1) == 0)
        re = FC_No;
    else
        re = FC_Vary;
    return re;
}

void get_fc_texture_name(char *line, e_floor_or_ceiling fc, t_texture_name **texture_name)
{
    char *name;

    while(isspace(*line))
        line++;
    line += 1;
    while(isspace(*line))
        line++;
    name = strdup(line);
    if(!name)
        ERR;
    if(fc == Floor)
        (*texture_name)->floor = name;
    else if(fc == Ceiling)
        (*texture_name)->ceiling = name;
}

void read_fc_color(t_texture_name **texture_name, int fd)
{
    char *line;
    int n;
    e_floor_or_ceiling fc;

    n = 0;
    while(1)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        fc = which_fc(line);
        if(fc ==  FC_Vary)
            ERR;
        else if(fc == FC_No)
        {
            free(line);
            continue;
        }
        else
        {
            n += 1;
            get_fc_texture_name(line, fc, texture_name);
        }
        free(line);
        if(n == 2)
            break;
    }
}

void print_map(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
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




void read_cub_file(char *argv)
{
    int file_fd;
    t_texture_name *texture_name;
    t_map_list *map_list;
    map_list = NULL;
    file_fd = open(argv,O_RDONLY);
    if(file_fd == -1)
        ERR;
    texture_name = new_texture_name();
    if(!texture_name)
        ERR;
    read_azimuths(&texture_name, file_fd);
    read_fc_color(&texture_name, file_fd);
    read_map(&map_list, file_fd);
    close(file_fd);

    map_check(&map_list);
    // printf("north:%s",texture_name->north);
    // printf("south:%s",texture_name->south);
    // printf("west:%s",texture_name->west);
    // printf("east:%s",texture_name->east);
    // printf("floor:%s",texture_name->floor);
    // printf("ceiling:%s",texture_name->ceiling);

    // char **map;
    // map = make_map(map_list);

    // print_map(map);

}

/**
 * texture check
*/
/**
 * 実行方法
 * make
 * ./cub3D map/map1.cub
 *  など
*/
int main(int argc, char **argv)
{
    if(argc != 2)
        ERR;
    check_file_name(argv[1]);
    read_cub_file(argv[1]);
    return 0;
}
