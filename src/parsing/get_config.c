/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 10:34:18 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 10:35:13 by dcresce          ###   ########.ch       */
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
	//VALIDATION DU FICHIER MAP
	//---------------------------------------------
	char	*ext;
	int		fd;

	ext = ft_strrchr(map_path, '.');
	if (!ext)
		return ;
	if (ft_strncmp(ext, ".cub", 5))
		return ;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return ;
	printf("yes\n");
	//close(fd);
	//---------------------------------------------
	//FIN DE LA VALIDATION

	//RECUPERATION DE LA MAP
	//---------------------------------------------
	char	**map;
	map = store_map(fd);
	print_map(map);
	free_split(map);
	//---------------------------------------------
	//FIN DE LA RECUPERATION
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
