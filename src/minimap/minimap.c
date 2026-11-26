/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:44:20 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 11:44:20 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	generate_minimap_buffer(t_config *conf, double *pos);
static void	draw_minimap(t_config *conf);

/**
 * @brief	Renders the minimap in the window
 * 
 * @param[in]	conf	cub3D configuration struct
 */
void	render_minimap(t_config *conf)
{
	conf->mp.width = conf->mlx.width * MP_PERCENT / 100;
	conf->mp.height = conf->mlx.height * MP_PERCENT / 100;
	conf->mp.offset_x = (conf->mlx.width - conf->mp.width) / 2;
	conf->mp.offset_y = (conf->mlx.height - conf->mp.height) / 2;
	conf->mp.minimap = init_minimap(conf->mp.width, conf->mp.height);
	if (!conf->mp.minimap)
		clean_exit(E_MALLOC, MALLOC, conf, NULL);
	generate_minimap_buffer(conf, conf->p_pos);
	draw_minimap(conf);
	mlx_put_image_to_window(conf->mlx.mlx, conf->mlx.win,
		conf->mlx.frame.img, 0, 0);
	free_split(conf->mp.minimap);
	conf->mp.minimap = NULL;
}

/**
 * @brief	Fills the minimap buffer
 * 
 * @param[in]	conf	Conf struct with minimap structure and sizes
 * @param[in]	pos		Player positions, here only to respect the 42 norm
 */
static void	generate_minimap_buffer(t_config *conf, double *pos)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;
	int	map_size[2];

	map_size[0] = count_lines(conf->map);
	y = -1;
	while (++y < conf->mp.height)
	{
		map_y = (int)floor(pos[1] + (double)(y - conf->mp.height / 2) / TS);
		map_size[1] = 0;
		if (map_y >= 0 && map_y < map_size[0])
			map_size[1] = (int)ft_strlen(conf->map[map_y]);
		x = -1;
		while (++x < conf->mp.width)
		{
			map_x = (int)floor(pos[0] + (double)(x - conf->mp.width / 2) / TS);
			if (map_x < 0 || map_y < 0 || map_y >= map_size[0]
				|| map_x >= map_size[1])
				conf->mp.minimap[y][x] = ' ';
			else
				conf->mp.minimap[y][x] = conf->map[map_y][map_x];
		}
	}
}

/**
 * @brief	Writes the minimap from the buffer to the window
 * 
 * @param[in]	conf	Config struct with minimap buffer and window dimension 
 */
static void	draw_minimap(t_config *conf)
{
	int	x;
	int	y;
	int	pos[2];

	y = -1;
	while (conf->mp.minimap[++y])
	{
		x = -1;
		while (conf->mp.minimap[y][++x])
		{
			if (conf->mp.minimap[y][x] == '1')
				put_pixel(&conf->mlx.frame, x + conf->mp.offset_x,
					y + conf->mp.offset_y, 0x00808080);
			else if (conf->mp.minimap[y][x] == '0')
				put_pixel(&conf->mlx.frame, x + conf->mp.offset_x,
					y + conf->mp.offset_y, 0x00FFFFFF);
			else
				put_pixel(&conf->mlx.frame, x + conf->mp.offset_x,
					y + conf->mp.offset_y, 0x0087CEEB);
		}
	}
	pos[0] = conf->mlx.width / 2 - 20;
	pos[1] = conf->mlx.height / 2 - 20;
	draw_square(&conf->mlx.frame, pos, 40, 0x00FF0000);
}
