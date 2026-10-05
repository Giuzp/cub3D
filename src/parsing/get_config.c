/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 21:17:34 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/05 21:32:28 by dcresce          ###   ########.ch       */
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
	close(fd);
	//---------------------------------------------
	//FIN DE LA VALIDATION
}

/**
 * @brief	Stores the map layout in an array
 * 
 * @param[in]	fd	File descriptor of the.cub map file
 * @return		A newly allocated char array with the map layout
 * 
 * The caller is responsible for freeing the returned array
 */
char	**store_map(int fd)
{
	
}

