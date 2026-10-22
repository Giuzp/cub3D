/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:14:16 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/22 14:14:16 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief	Loads the map configuration from a .cub file
 *
 * @param[in]	map_path	Path to the .cub map file
 * @return		A newly allocated configuration on success, NULL on failure
 *
 * The caller is responsible for freeing the returned configuration
 */
void	get_config(char *map_path)
{
	t_config	*config;
	char		*ext;
	int			fd;
	char		**map;
	int			p_pos[2];

	config = NULL;
	ext = ft_strrchr(map_path, '.');
	if (!ext)
		clean_exit(E_EXT, EXT, NULL, NULL);
	if (ft_strncmp(ext, ".cub", 5))
		clean_exit(E_EXT, EXT, NULL, NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		clean_exit(E_OPEN, OPEN, NULL, NULL);
	config = read_store_cubfile(fd, map_path);
	map = store_map(fd);
	validate_map(map, p_pos, &(config->p_dir));
	free_split(map);
	clean_config(config);
	close(fd);
}

//HELPER FUNCTIONS TO DESTROY LATER
//---------------------------------------------------------------
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
