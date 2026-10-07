/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:32:13 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/07 20:32:19 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*get_map_in_one_string(int fd);
static void	check_for_empty_lines(char *map_ol);

/**
 * @brief	Stores the map layout in an array
 * 
 * @param[in]	fd	File descriptor of the .cub map file
 * @return		A newly allocated char array with the map layout
 * 
 * The caller is responsible for freeing the returned array
 */
char	**store_map(int fd)
{
	char	**map;
	char	*map_one_liner;
	char	*temp;

	temp = get_map_in_one_string(fd);
	if (!temp)
		exit(2);
	map_one_liner = ft_strtrim(temp, "\n");
	free(temp);
	temp = NULL;
	check_for_empty_lines(map_one_liner);
	map = ft_split(map_one_liner, '\n');
	free(map_one_liner);
	map_one_liner = NULL;
	return (map);
}

/**
 * @brief	Stores the map in one string
 * 
 * @param[in]	fd	File descriptor of the .cub map file
 * @return		A newly allocated string with the map
 * 
 * The caller is responsible for freeing the returned string
 */
static char	*get_map_in_one_string(int fd)
{
	char	*temp;
	char	*line;
	char	*new_line;

	new_line = gnl(fd);
	if (!new_line)
		exit (1);
	line = ft_strdup("");
	while (new_line)
	{
		temp = line;
		line = ft_strjoin(temp, new_line);
		free(temp);
		temp = NULL;
		if (!line)
			return (close(fd), free(new_line), free(line), free(temp), NULL);
		free(new_line);
		new_line = NULL;
		new_line = gnl(fd);
	}
	return (close(fd), free(new_line), line);
}

/**
 * @brief	Checks if in the map there is an empty line
 * 
 * @param[in]	map_ol	The map on one line
 */
static void	check_for_empty_lines(char *map_ol)
{
	int	i;

	i = 0;
	while (map_ol[i])
	{
		if (map_ol[i] == '\n')
		{
			if (i < (int)ft_strlen(map_ol))
			{
				if (map_ol[i + 1] == '\n')
					clean_exit(E_EMPTY_L, EMPTY_L);
			}
		}
		i++;
	}
}
