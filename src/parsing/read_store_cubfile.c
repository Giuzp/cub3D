/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_store_cubfile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:56:13 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 18:55:01 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			parse_line(char **line, t_exit_code *exit_code);
char		**read_fd(int fd, char *map_path, t_exit_code *exit_code);
int			parse_colour_and_texture(int fd, char **buffer,
				t_exit_code *exit_code);

/**
 * @brief	Reads texture and color data into a config struct
 *
 * @param[in]	fd			Map file descriptor, closed while checking the file
 * @param[in]	map_path	Path used to reopen the map file
 * @return		A newly allocated config struct
 *
 * The caller is responsible for freeing the returned configuration
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
	config = config_init(buffer, exit_code);
	free_split(buffer);
	if (!config)
		clean_exit(exit_code->code, exit_code->message, config, exit_code);
	free(exit_code);
	return (config);
}

/**
 * @brief	Checks the configuration order and reads its six lines
 *
 * @param[in]	fd			Map file descriptor, closed during the initial check
 * @param[in]	map_path	Path used to reopen the map file
 * @param[in,out]	exit_code	Exit code struct used for error handling
 * @return		An allocated array containing the configuration lines
 *
 * The caller is responsible for freeing the returned array
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
	buffer = ft_calloc(sizeof(char *), (6 + 1));
	if (!buffer)
		close_exit_clean(fd, E_MALLOC, MALLOC, exit_code);
	parse_colour_and_texture(fd, buffer, exit_code);
	close(fd);
	return (buffer);
}

/**
 * @brief	Validates and stores the texture and color lines
 *
 * @param[in]	fd			Map file descriptor to read
 * @param[out]	buffer		Allocated array to fill with copies of the lines
 * @param[in,out]	exit_code	Exit code struct used for error handling
 * @return		0 on success; exits on error
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
			buffer[i] = ft_strndup(line, ft_strlen(line) - 1);
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

/**
 * @brief	Trims spaces and checks the configuration identifier
 *
 * @param[in,out]	line		Allocated line to trim and replace
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		0 on success or an empty line, 1 on error
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
	*line = ft_strdup(buffer);
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
