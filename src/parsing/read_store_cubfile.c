#include "cub.h"

int parse_line(char *line, t_exit_code *exit_code);
char    **read_fd(int fd, char *map_path, t_exit_code *exit_code);

int    read_store_cubfile(int fd, char *map_path)
{
    char **buffer;
    t_exit_code	*exit_code;

    exit_code = ft_calloc(1, sizeof(t_exit_code));
    if (exit_code == NULL)
        clean_exit(E_MALLOC, MALLOC, NULL, NULL);
    buffer = NULL;
    buffer = read_fd(fd, map_path, exit_code);
    if (!buffer)
        return (0);
    free_split(buffer);
    return (0);
}

char    **read_fd(int fd, char *map_path, t_exit_code *exit_code)
{
    int     i;
    int     len;
    char    *line;
    char    **buffer;

    buffer = NULL;
    i = 0;
    len = check_map_is_ok(fd, exit_code);
    if (len == 1)
        clean_exit(exit_code->code, exit_code->message, 0, exit_code);
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        clean_exit(E_OPEN, OPEN, 0, exit_code);
    line = gnl(fd);
    if (!line)
    {
        close(fd);
        clean_exit(E_OPEN, OPEN, NULL, exit_code);
    }
    buffer = calloc(sizeof(char*) , (6 + 1));
    if (!buffer)
        clean_exit(E_MALLOC, MALLOC, NULL, exit_code);
    while (line && i < 6)
    {
        if (parse_line(line, exit_code))
        {
            close(fd);
            free(line);
            free_split(buffer);
            return(clean_exit(exit_code->code, exit_code->message, 0, exit_code), NULL);
        }
        if (line[0] != '\n')
        {
            buffer[i] = ft_strdup(line);
            if (!buffer[i])
                 clean_exit(E_MALLOC, MALLOC, NULL, exit_code);
            i++;
        }
        free_and_null(&line);
        line = gnl(fd);
    }
    close(fd);
    free_and_null(&line);
    free(exit_code);
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



