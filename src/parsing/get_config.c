/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:14:14 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/27 21:14:19 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_config	*conf_init(void);

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
	char		*ext;
	int			fd;
	char		**map;
	int			p_pos[2];

	ext = ft_strrchr(map_path, '.');
	if (!ext)
		clean_exit(E_EXT, EXT, NULL, NULL);
	if (ft_strncmp(ext, ".cub", 5))
		clean_exit(E_EXT, EXT, NULL, NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		clean_exit(E_OPEN, OPEN, NULL, NULL);
	conf = conf_init();
	//conf = read_store_cubfile(fd, map_path);
	map = store_map(fd);
	validate_map(map, p_pos, &(conf->p_dir));
	conf->map = map;
	close(fd);
	return (conf);
}

static t_config	*conf_init(void)
{
	t_config	*conf;

	conf = ft_calloc(1, sizeof(*conf));
	if (!conf)
		clean_exit(E_MALLOC, MALLOC, NULL, NULL);
	return (conf);
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
