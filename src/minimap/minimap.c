/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:21:09 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/24 14:25:37 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	generate_minimap_buffer(t_config *conf);
static void	draw_minimap(t_config *conf);

/**
 * @brief	Renders the minimap in the window
 * 
 * @param[in]	conf	cub3D configuration struct
 */
void	render_minimap(t_config *conf)
{
	conf->mp.minimap = init_minimap();
	if (!conf->mp.minimap)
		clean_exit(E_MALLOC, MALLOC, conf, NULL);
	generate_minimap_buffer(conf);
	draw_minimap(conf);
	mlx_put_image_to_window(conf->mlx.mlx, conf->mlx.win,
		conf->mlx.frame.img, 0, 0);
	free_split(conf->mp.minimap);
	conf->mp.minimap = NULL;
}

static void	generate_minimap_buffer(t_config *conf)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	double	*pos;

	pos = conf->p_pos;
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

static void	draw_minimap(t_config *conf)
{
	int	x;
	int	y;

	y = 0;
	while (conf->mp.minimap[y])
	{
		x = 0;
		while (conf->mp.minimap[y][x])
		{
			if (conf->mp.minimap[y][x] == '1')
				put_pixel(&conf->mlx.frame, x, y, 0x00808080);
			else if (conf->mp.minimap[y][x] == '0')
				put_pixel(&conf->mlx.frame, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	draw_square(&conf->mlx.frame, LENGTH / 2, WIDTH / 2, 10, 0x00FF0000);
}
