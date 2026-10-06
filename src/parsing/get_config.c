/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:15:08 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 21:15:08 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//HELPER FUNCTIONS TO DESTROY LATER
static void	print_map(char **map);

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
	print_map(map);
	p_dir = '\0';
	validate_map(map, p_pos, &p_dir);
	printf("Validated: x=%d, y=%d, dir=%c\n", p_pos[0], p_pos[1], p_dir);
	free_split(map);
	//---------------------------------------------
	//FIN DE LA RECUPERATION ET VALIDATION

	close(fd);
}

//HELPER FUNCTIONS TO DESTROY LATER
//---------------------------------------------------------------
static void	print_map(char **map)
{
	int i = 0;

	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
