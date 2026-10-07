/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:29:46 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/07 20:30:00 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief	Counts the number of lines in an array
 * 
 * @param[in]	map	The map of the game (array)
 * @return		Returns the number of lines in int format
 */
int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

/**
 * @brief	Duplicates a given array
 * 
 * @param[in]	array	Array to duplicate
 * @return		A newly allocated copy of the array
 * 
 * The caller is responsible for freeing the returned array
 */
char	**dup_array(char **array)
{
	char	**dup;
	int		len;
	int		i;
	int		j;

	len = count_lines(array);
	dup = ft_calloc(sizeof(char *), len + 1);
	if (!dup)
		clean_exit(E_MALLOC, MALLOC);
	i = -1;
	while (array[++i])
	{
		j = -1;
		dup[i] = ft_calloc(sizeof(char), ft_strlen(array[i]) + 1);
		if (!dup[i])
		{
			free_split(dup);
			clean_exit(E_MALLOC, MALLOC);
		}
		while (array[i][++j])
			dup[i][j] = array[i][j];
	}
	return (dup);
}

bool	check_for_missing_spots(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				return (*x = j, *y = i, true);
			j++;
		}
		i++;
	}
	return (false);
}
