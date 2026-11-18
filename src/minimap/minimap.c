/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 22:22:20 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/18 22:23:48 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	GenerateMinimapBuffer(t_config *conf);
static void	print_minimap(char **buffer);

void	render_minimap(t_config *conf)
{
	//======================================
	//INIT AND FILL THE MINIMAP
	conf->mp.minimap = init_minimap();
	if (!conf->mp.minimap)
		clean_exit(E_MALLOC, MALLOC, conf, NULL);
	GenerateMinimapBuffer(conf);
	print_minimap(conf->mp.minimap);
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

/*TODO: destroy later*/
static void	print_minimap(char **buffer)
{
	int	x;
	int	y;

	y = -1;
	while (y <= (MP_HEIGHT - 1) / TILE_SIZE + 1)
	{
		x = -1;
		while (x <= (MP_WIDTH - 1) / TILE_SIZE + 1)
		{
			if (y == -1 || y == (MP_HEIGHT - 1) / TILE_SIZE + 1)
			{
				if (x == -1 || x == (MP_WIDTH - 1) / TILE_SIZE + 1)
					ft_putchar_fd('+', 1);
				else
					ft_putchar_fd('-', 1);
			}
			else if (x == -1 || x == (MP_WIDTH - 1) / TILE_SIZE + 1)
				ft_putchar_fd('|', 1);
			else
				ft_putchar_fd(buffer[y * TILE_SIZE][x * TILE_SIZE], 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}
