#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * attention
 * Except for the map content, each type of element can be separated by one or more empty line(s).
*/
static void error(char *str);

typedef struct s_azimuth
{
    char   *north;
    char   *south;
    char   *west;
    char   *east;
}			t_azimuth;

/**
 * Check if the file ends with *.cub
*/
void check_file_name(char *str)
{
    int i;

    i = 0;
    if(!str  || !*str)
    {
        error("Error   File name is empty.\n");
        return ;
    }
    while(str[i])
        i++;
    if(str[i - 4] == '.' && str[i - 3] == 'c' && str[i - 2] == 'u' && str[i - 1] == 'b')
    {
    write(1, "OK\n", 3);
        return ;
    }
    error("Error     File name is not *.cub.\n");
}

/**
 * get_next_line
*/

/**
 * North or not. 
*/

void check_north(char *str)
{
    int i;
    char *north_texture;

    i = 0;
    // if(!str  || !*str)
    // {
    //     error("Error   File name is empty.\n");
    //     return ;
    // }
    str+=2;
    while(is_space(*str))
        str++;
    north_texture = strdup(str);        

}

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


/**
 * texture check
*/
int main()
{
    char *str = "NO ./path_to_the_north_texture";

    return 0;
}

/**
 * filenamecheck
*/
// int main()
// {
//     /**
//      * ファイル名が".cub"で終わっているか確認するためのテストの文字列を１０個 
//      * 例)char *filename = "map..cub";
//     */
//     char *filename = "map.cub";
//     char *filename1 = "map.cu";
//     char *filename2 = "map.c";
//     char *filename3 = "map.";
//     char *filename4 = "map";
//     char *filename5 = "map.cub";
//     char *filename6 = "map.cu";
//     char *filename7 = "map.c";
//     char *filename8 = "map.";
//     char *filename9 = "map";
//     char *filename10 = "";
//     char *filename11 = NULL;

//     check_file_name(filename);
//     check_file_name(filename1);
//     check_file_name(filename2);
//     check_file_name(filename3);
//     check_file_name(filename4);
//     check_file_name(filename5);
//     check_file_name(filename6);
//     check_file_name(filename7);
//     check_file_name(filename8);
//     check_file_name(filename9);
//     check_file_name(filename10);
//     check_file_name(filename11);

//     return 0;
// }

static void error(char *str)
{
    // printf("%s\n", str);
    write(1, str, strlen(str));
    // exit(1);
    return ;
}