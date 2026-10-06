/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 10:34:03 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 10:34:03 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*get_map_in_one_string(int fd);

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
