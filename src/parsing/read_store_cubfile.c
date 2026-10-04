#include "cub.h"

char    **read_fd(char *cube_file)
{
    int     i;    
    int     fd;
    char    line;
    char    **buffer;

    i = 0;
    fd = open(cube_file, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        return (NULL);
    }
    while (line)
    {
        buffer[i++] = line;
        line = get_next_line(fd);
    }
    close(fd);
    return (buffer);
}

int    read_store_cubfile(char *cube_file, t_cube cube)
{
    cube->brut = read_fd(cube_file);
    if (!cube->brut)
        return (clean_and_exit(cube)); // fonction a faire
}