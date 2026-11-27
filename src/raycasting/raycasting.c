/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:57:05 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/27 14:57:05 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_column(t_config *conf, int i);

/**
 * @brief	Renders one frame of the game
 * 
 * @param[in]	conf	config struct
 */
void	render_game(t_config *conf)
{
	int	i;

	i = 0;
	while (i < conf->mlx.width)
	{
		draw_column(conf, i);
		i++;
	}
}

/**
 * @brief	Draws one column of the frame
 * 
 * @param[in]	conf	config struct
 * @param[in]	i		column to draw
 */
static void	draw_column(t_config *conf, int i)
{
	t_column	*col;

	col = ft_calloc(sizeof(t_column), 1);
	//-------------------------------------
	// CALCULATE COLUMN
	calculate_dist(conf, col, i);
	// END OF CALCULATE COLUMN
	//-------------------------------------

	//-------------------------------------
	// RENDER COLUMN
	render_column(conf, col, i);
	// END OF RENDER COLUMN
	//-------------------------------------
	free(col);
}
