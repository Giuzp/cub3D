/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:04:57 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 21:05:02 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_chars_and_pos(char **map, int p_pos[2], char *p_dir);

/**
 * @brief	Validates map shape and content
 * 
 * @param[in]	map		An array representing the map to validate
 * @param[out]	p_pos	Position of the player in the map
 * @param[out]	p_dir	Direction where the player is looking
 * 
 * p_dir should be NULL when calling the function
 */
void	validate_map(char **map, int p_pos[2], char *p_dir)
{
	check_chars_and_pos(map, p_pos, p_dir);
}

/**
 * @brief	Checks for the chars used in the map and the player position
 * 
 * @param[in]	map		An array representing the map to validate
 * @param[out]	p_pos	Position of the player in the map
 * @param[out]	p_dir	Direction where the player is looking
 */
static void	check_chars_and_pos(char **map, int p_pos[2], char *p_dir)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01NSWE ", map[i][j]))
				clean_exit(E_CHAR_UN, CHAR_UN);
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (*p_dir)
					clean_exit(E_MULT_P, MULT_P);
				p_pos[0] = j;
				p_pos[1] = i;
				*p_dir = map[i][j];
			}
			j++;
		}
		i++;
	}
	if (!*p_dir)
		clean_exit(E_NO_P, NO_P);
}
