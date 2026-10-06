/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:16:51 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 15:18:28 by dcresce          ###   ########.ch       */
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
		clean_exit(E_EXT, EXT);
	if (ft_strncmp(ext, ".cub", 5))
	clean_exit(E_EXT, EXT);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		clean_exit(E_OPEN, OPEN);
	close(fd);
	//---------------------------------------------
	//FIN DE LA VALIDATION
}
