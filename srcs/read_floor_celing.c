#include "cub3d.h"

static e_floor_or_ceiling which_fc(char *line)
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

static void get_fc_texture_name(char *line, e_floor_or_ceiling fc, t_texture_name **texture_name)
{
    char *name;

    while(isspace(*line))
        line++;
    line += 1;
    while(isspace(*line))
        line++;
    name = strdup(line);
    if(!name)
        MALLOC_ERR;
    name = delete_line_break(name);
    if(fc == Floor)
        (*texture_name)->floor = name;
    else if(fc == Ceiling)
        (*texture_name)->ceiling = name;
}

int read_fc_color(t_texture_name **texture_name, int fd)
{
    char *line;
    int n;
    e_floor_or_ceiling fc;

    n = 0;
    while(1)
    {
        line = get_next_line(fd);
        if(line == NULL)
        {
            // free_azimuths(*texture_name);
            return error("Error: ", "Invalid file: ", "No Floor or Celing", EXIT_FAILURE);
        }
        fc = which_fc(line);
        if(fc ==  FC_Vary)
        {
            // free_azimuths(*texture_name);
            return error("Error: ", "Invalid file: ", "Vary Floor or Celing", EXIT_FAILURE);
        }
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
    return 0;
}
