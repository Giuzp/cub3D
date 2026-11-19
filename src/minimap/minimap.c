/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:46:39 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/19 18:46:46 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	GenerateMinimapBuffer(t_config *conf);


/**
 * @brief	Renders the minimap in the window
 * 
 * @param[in]	conf	cub3D configuration struct
 */
void	render_minimap(t_config *conf)
{
	//======================================
	//INIT AND FILL THE MINIMAP
	conf->mp.minimap = init_minimap();
	if (!conf->mp.minimap)
		clean_exit(E_MALLOC, MALLOC, conf, NULL);
	GenerateMinimapBuffer(conf);
	//END OF INIT AND FILL THE MINIMAP
	//======================================
	
	//======================================
	//RENDER THE MINIMAP

	//END OF RENDER THE MINIMAP
	//======================================

	//======================================
	//FREE THE MINIMAP
	free_split(conf->mp.minimap);
	conf->mp.minimap = NULL;
	//END OF FREE THE MINIMAP
	//======================================
}

static void	GenerateMinimapBuffer(t_config *conf)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	double	*pos = conf->p_pos;

	y = 0;
	while (y < MP_HEIGHT)
	{
		map_y = (int)floor(pos[1] + (double)(y - MP_HEIGHT / 2) / TILE_SIZE);
		x = 0;
		while (x < MP_WIDTH)
		{
			map_x = (int)floor(pos[0] + (double)(x - MP_WIDTH / 2) / TILE_SIZE);
			if (map_x < 0 || map_y < 0 || map_y >= count_lines(conf->map)
				|| map_x >= (int)ft_strlen(conf->map[map_y]))
				conf->mp.minimap[y][x] = ' ';
			else
				conf->mp.minimap[y][x] = conf->map[map_y][map_x];
			x++;
		}
		y++;
	}
}
