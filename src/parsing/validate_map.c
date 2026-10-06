/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:19:47 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 22:22:45 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_chars_and_pos(char **map, int p_pos[2], char *p_dir);
static void	flood_fill(char **map, int x, int y);
static int	count_lines(char **map);

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
	flood_fill(map, p_pos[0], p_pos[1]);
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


static void	flood_fill(char **map, int x, int y)
{
	if (y < 0 || y >= count_lines(map))
		clean_exit(E_OPEN_MAP, OPEN_MAP);
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		clean_exit(E_OPEN_MAP, OPEN_MAP);
	if ((map[y][x] == 'f') || map[y][x] == '1')
		return ;
	if (ft_strchr("NSWE0", map[y][x]))
		map[y][x] = 'f';
	else if ((y == 0) || (y == count_lines(map))
		|| (x == 0) || (x == (int)ft_strlen(map[y])))
		clean_exit(E_OPEN_MAP, OPEN_MAP);
	else if (map[y][x] == ' ')
		clean_exit(E_HOLE_MAP, HOLE_MAP);
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}


static int	count_lines(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
		i++;
	return (i);
}