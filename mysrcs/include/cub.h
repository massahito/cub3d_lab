#ifndef CUB_H
# define CUB_H
// includes
# include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include "get_next_line.h"
# define ERR error()
//window size
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

// linux keycode
# define ESC		65307
# define W_KEY	119
# define S_KEY	115
# define D_KEY	100
# define A_KEY	97
# define R_ALW	65363
# define L_ALW	65361

//mac keycode
// # define ESC 53
// # define W_KEY 13
// # define S_KEY 1
// # define D_KEY 2
// # define A_KEY 0
// # define R_ALW 124
// # define L_ALW 123

/**    X  */
#define C 88
/**    1  */
// #define C 49

typedef struct s_map_list t_map_list;
struct s_map_list
{
    char *line;
    t_map_list *next;
    t_map_list *prev;
};
//function prototypes
//main.c
void read_map(t_map_list **map_list, int fd);
void error(void);
size_t map_list_size(t_map_list *map_list);
bool is_no_str(char *line);
void map_check(t_map_list **map_list);
t_map_list  *new_map_list(char *line);
t_map_list *map_last(t_map_list *map_list);
char **make_map(t_map_list *map_list);
void print_map(char **map);

//file_name_check.c
bool check_file_name(char *str);

#endif