/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:42:34 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 14:45:51 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_path(char *path);

/**
 * @brief	Loads the map configuration from a .cub file
 *
 * @param[in]	map_path	Path to the .cub map file
 * @return		A newly allocated configuration on success, NULL on failure
 *
 * The caller is responsible for freeing the returned configuration
 */
t_config	*get_config(char *map_path)
{
	t_config	*conf;
	int			fd;
	char		**map;
	int			p_pos[2];

	fd = check_path(map_path);
	if (fd < 0)
		clean_exit(E_OPEN, OPEN, NULL, NULL);
	conf = read_store_cubfile(fd, map_path);
	map = store_map(fd);
	validate_map(map, p_pos, &(conf->p_dir));
	conf->p_pos[0] = p_pos[0] + 0.5;
	conf->p_pos[1] = p_pos[1] + 0.5;
	conf->map = map;
	close(fd);
	return (conf);
}

/**
 * @brief	Check if the given path to the map file is correct
 * 
 * @param[in]	path	The given path to the map
 * @return		The fd of the map file
 * 
 * The fd will be -1 in case of error
 */
static int	check_path(char *path)
{
	char	*ext;
	int		fd;

	ext = ft_strrchr(path, '.');
	if (!ext)
		clean_exit(E_EXT, EXT, NULL, NULL);
	if (ft_strncmp(ext, ".cub", 5))
		clean_exit(E_EXT, EXT, NULL, NULL);
	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	return (fd);
}

/**
 * @brief	Checks if all the paths and colors have been found
 * 
 * @param[in]	id	id struct
 * 
 * Used in check_map_is_ok, here only to respect norminette
 */
int	check_all_id(t_check_id *id)
{
	if (id->no_id == false)
		return (0);
	if (id->so_id == false)
		return (0);
	if (id->ea_id == false)
		return (0);
	if (id->we_id == false)
		return (0);
	if (id->f_id == false)
		return (0);
	if (id->c_id == false)
		return (0);
	return (1);
}

//HELPER FUNCTIONS TO DESTROY LATER
//---------------------------------------------------------------
/**
 * @brief	Prints the map in the terminal
 *
 * @param[in]	map	Array containing the map lines
 */
void	print_map(char **map)
{
	int	i = 0;

	printf("\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
