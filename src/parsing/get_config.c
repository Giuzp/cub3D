/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:23:17 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 15:37:08 by jturrel          ###   ########.fr       */
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

	//SPACE FOR NEW FUNCTIONS
	read_store_cubfile(argv[1]);
    
	close(fd);
}
