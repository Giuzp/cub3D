/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:51:19 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/27 14:51:55 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_column(t_config *conf, int i);

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
}
