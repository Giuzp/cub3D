#include "cub.h"

int		parse_line(char **line, t_exit_code *exit_code);
char	**read_fd(int fd, char *map_path, t_exit_code *exit_code);
int		parse_colour_and_texture(int fd, char **buffer, t_exit_code *exit_code);

/*This function is the main function for parsing
 * texture and colours. Buffer is initialized here
 * for putting values from map in our struct.
 */

t_config	*read_store_cubfile(int fd, char *map_path)
{
	char		**buffer;
	t_exit_code	*exit_code;
	t_config	*config;

	config = NULL;
	exit_code = ft_calloc(1, sizeof(t_exit_code));
	if (exit_code == NULL)
		clean_exit(E_MALLOC, MALLOC, NULL, NULL);
	buffer = NULL;
	buffer = read_fd(fd, map_path, exit_code);
	config = config_init(buffer, exit_code); // if config = nULL ....
	free_split(buffer);
	if (!config)
		clean_exit(exit_code->code, exit_code->message, config, exit_code);
	free(exit_code);
	return (config);
}

/*
 * first check for parsing if map is after colours and texture
 * Then we parse colours and textures values line by line.
 */

char	**read_fd(int fd, char *map_path, t_exit_code *exit_code)
{
	char	**buffer;

	buffer = NULL;
	if (check_map_is_ok(fd, exit_code))
		clean_exit(exit_code->code, exit_code->message, 0, exit_code);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		clean_exit(E_OPEN, OPEN, 0, exit_code);
	buffer = calloc(sizeof(char *), (6 + 1));
	if (!buffer)
		close_exit_clean(fd, E_MALLOC, MALLOC, exit_code);
	parse_colour_and_texture(fd, buffer, exit_code);
	close(fd);
	return (buffer);
}

/*
 * During GNL, we parse directly the line, if not correct we exit
 * and free everything. Else if correct, we put in buffer by a dup for
 * free line and avoid leeks.
 */
int	parse_colour_and_texture(int fd, char **buffer, t_exit_code *exit_code)
{
	int		i;
	char	*line;

	i = 0;
	line = gnl(fd);
	if (!line)
		close_exit_clean(fd, E_OPEN, OPEN, exit_code);
	while (line && i < 6)
	{
		if (parse_line(&line, exit_code))
			clean_while_read(fd, line, buffer, exit_code);
		if (line[0] != '\n')
		{
			buffer[i] = ft_strdup(line);
			if (!buffer[i])
				clean_while_read(fd, line, buffer, exit_code);
			i++;
		}
		free_and_null(&line);
		line = gnl(fd);
	}
	free_and_null(&line);
	return (0);
}

/*
 * In case the line are full of space, we first trim the line.
 * Then we check the identifier.
 */
int	parse_line(char **line, t_exit_code *exit_code)
{
	int		i;
	char	*buffer;

	i = 0;
	if (*line[0] == '\n')
		return (0);
	buffer = NULL;
	buffer = ft_strtrim(*line, " ");
	free_and_null(line);
	*line = ft_strdup(buffer); // leak ?
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
