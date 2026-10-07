/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:30:20 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/07 20:31:25 by dcresce          ###   ########.ch       */
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
	char	*ext;
	int		fd;

	ext = ft_strrchr(map_path, '.');
	if (!ext)
		clean_exit(E_EXT, EXT);
	if (ft_strncmp(ext, ".cub", 5))
		clean_exit(E_EXT, EXT);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		clean_exit(E_OPEN, OPEN);

	//RECUPERATION ET VALIDATION DE LA MAP
	//---------------------------------------------
	char	**map;
	int		p_pos[2];
	char	p_dir;
	map = store_map(fd);
	p_dir = '\0';
	validate_map(map, p_pos, &p_dir);
	free_split(map);
	//---------------------------------------------
	//FIN DE LA RECUPERATION ET VALIDATION

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
