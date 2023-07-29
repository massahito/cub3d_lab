#include "cub3d.h"

static e_azimuth which_azimuth(char *line)
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

static void get_azimuth_texture_name(char *line, e_azimuth azimuth, t_texture_name **azimuths)
{
    char *texture_name;

    while(isspace(*line))
        line++;
    line += 2;
    while(isspace(*line))
        line++;
    texture_name = strdup(line);
    if(!texture_name)
        MALLOC_ERR;
    if(azimuth == North)
        (*azimuths)->north = texture_name;
    else if(azimuth == South)
        (*azimuths)->south = texture_name;
    else if(azimuth == West)
        (*azimuths)->west = texture_name;
    else if(azimuth == East)
        (*azimuths)->east = texture_name;
}

int read_azimuths(t_texture_name **texture_name, int fd)
{
    e_azimuth azimuth;
    char *line;
    int n;

    n = 0;
    while(1)
    {
        line = get_next_line(fd);
        if(line == NULL)
        {
            // free_azimuths(*texture_name);
            return error("Error: ", "Invalid file: ", "No azimuths", EXIT_FAILURE);
        }
        azimuth = which_azimuth(line);
        if(azimuth ==  AZIMUTH_Vary)
        {
            // free_azimuths(*texture_name);
            return error("Error: ", "Invalid file: ", "Vary azimuths", EXIT_FAILURE);
        }
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
    return 0;
}