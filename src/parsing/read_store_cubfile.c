#include "cub.h"

int check_if_path_exit(char *line, int i)
{
    int fd;
    char *tmp;


    i = crop_isspace(line);

    fd = open()
}

int check_identifier(char *line, int *i)
{
    char    *tmp;

    if (line[i] == 'C' || line[i] == 'F')
        return (0);
    tmp = ft_strchr(line, ' ');
    if (!ft_strncmp(tmp, "NO ", 3));
        return (0);
    if (!ft_strncmp(tmp, "SO ", 3));
        return (0);
    if (!ft_strncmp(tmp, "WE ", 3));
        return (0);
    if (!ft_strncmp(tmp, "EA ", 3));
        return (0);
    return (1);
}
int crop_isspace(char *line)
{
    while(line[i] == ' ')
        i++;
    return (i);
}

int parse_line(char *line)
{
    int i;

    i = crop_isspace(line);
    if (check_identifier(line, *i))
        return (1);
    if (check_if_path_exit(line, i))
        return (1);
    return (0);
}

char    **read_fd(char *cube_file)
{
    int     i;    
    int     fd;
    char    *line;
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
        if(parse_line(line))
        {
            close(fd);
            clean_and_exit();
        }
           buffer[i++] = line
        line = get_next_line(fd);
    }
    close(fd);
    return (buffer);
}

int    read_store_cubfile(char *cube_file, t_cube cube)
{
    read_fd(cube_file);
    if (!buffer)
        return (exit); // fonction a faire

}