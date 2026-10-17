#include "cub.h"

int parse_line(char *line, t_exit_code *exit_code);
char    **read_fd(int fd, char *map_path);

int    read_store_cubfile(int fd, char *map_path)
{
    read_fd(fd, map_path);
    return (0);
}

char    **read_fd(int fd, char *map_path)
{
    int     i;
    int     len;
    char    *line;
    char    **buffer;
    t_exit_code	*exit_code;

    exit_code = ft_calloc(1, sizeof(t_exit_code));
    if (exit_code == NULL)
        return NULL;
    buffer = NULL;
    i = 0;
    len = check_map_is_ok(fd, exit_code);
    fd = open(map_path, O_RDONLY);
    line = gnl(fd);
    buffer = malloc(sizeof(char*) * (len + 1));
    if (!buffer)
        return (NULL);
    if (!line)
    {
        close(fd);
        clean_exit(E_OPEN, OPEN, NULL, NULL);
    }
    while (line)
    {
        if (parse_line(line, exit_code))
        {
            close(fd);
            free(line);
            clean_exit(exit_code->code, exit_code->message, 0, exit_code);
        }
        buffer[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
        buffer[i++] = line;
        line = gnl(fd);
    }
    close(fd);
    return (buffer);
}

int parse_line(char *line, t_exit_code *exit_code)
{
    int i;
    char    *buffer;

    i = 0;
    if (line[0] == '\n')
        return (0);
    buffer = NULL;
    buffer = ft_strtrim(line, " ");
    if (!buffer)
    {
        exit_code_init(exit_code, E_MALLOC, MALLOC);
        return (1);
    }
    if (check_identifier(buffer, &i, exit_code))
        return (free_and_null(&buffer), 1);
    free_and_null(&buffer);
    return (0);
}



