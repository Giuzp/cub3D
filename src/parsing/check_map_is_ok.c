/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_ok.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:52:02 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 14:52:41 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_id(t_check_id *id);
int		check_id(char **line, t_check_id *id, int fd);
int		check_flag_id(t_check_id *id, t_exit_code *exit_code);
void	close_and_free(int fd, char *line);

/**
 * @brief	Checks that all required identifiers appear before the map
 *
 * @param[in]	fd			Map file descriptor, closed by this function
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		0 on success, 1 on error
 */
int	check_map_is_ok(int fd, t_exit_code *exit_code)
{
	char		*line;
	t_check_id	id[6];

	init_id(id);
	line = gnl(fd);
	if (!line || line[0] == 1)
	{
		close(fd);
		if (!line)
			exit_code_init(exit_code, E_EMPTY, EMPTY);
		else
			exit_code_init(exit_code, E_WRO_O, WRO_O);
		return (1);
	}
	if (check_id(&line, id, fd))
	{
		close_and_free(fd, line);
		exit_code_init(exit_code, E_SCENE_W, SCENE_W);
		return (1);
	}
	close_and_free(fd, line);
	return (check_flag_id(id, exit_code));
}

/**
 * @brief	Initializes the identifier flags to false
 *
 * @param[out]	id	Struct containing the identifier flags
 */
void	init_id(t_check_id *id)
{
	id->no_id = false;
	id->so_id = false;
	id->we_id = false;
	id->ea_id = false;
	id->f_id = false;
	id->c_id = false;
}

/**
 * @brief	Reads configuration lines and marks the identifiers found
 *
 * @param[in,out]	line	Current line, replaced while reading the file
 * @param[out]		id		Struct containing the identifier flags
 * @param[in]		fd		Map file descriptor to read
 * @return		0 when the map is reached, 1 on an unknown identifier
 */
int	check_id(char **line, t_check_id *id, int fd)
{
	while (*line[0] != '1' && !check_all_id(id))
	{
		if (*line[0] == ' ')
		{
			*line = trim_line(*line);
			continue ;
		}
		if (*line[0] == 'N')
			id->no_id = true;
		else if (*line[0] == 'S')
			id->so_id = true;
		else if (*line[0] == 'W')
			id->we_id = true;
		else if (*line[0] == 'E')
			id->ea_id = true;
		else if (*line[0] == 'F')
			id->f_id = true;
		else if (*line[0] == 'C')
			id->c_id = true;
		else if (*line[0] != '\n')
			return (1);
		free_and_null(line);
		*line = gnl(fd);
	}
	return (0);
}

/**
 * @brief	Closes the file descriptor and frees the current line
 *
 * @param[in]	fd		File descriptor to close
 * @param[in]	line	Allocated line to free
 */
void	close_and_free(int fd, char *line)
{
	(void)fd;
	if (line)
		free(line);
}

/**
 * @brief	Checks that all required identifier flags are set
 *
 * @param[in]	id			Struct containing the identifier flags
 * @param[out]	exit_code	Exit code struct to fill if an identifier is missing
 * @return		0 if all identifiers were found, 1 otherwise
 */
int	check_flag_id(t_check_id *id, t_exit_code *exit_code)
{
	if (id->no_id == true)
	{
		if (id->so_id == true)
		{
			if (id->we_id == true)
			{
				if (id->ea_id == true)
				{
					if (id->f_id == true)
					{
						if (id->c_id == true)
						{
							return (0);
						}
					}
				}
			}
		}
	}
	exit_code_init(exit_code, E_WRO_O, WRO_O);
	return (1);
}
