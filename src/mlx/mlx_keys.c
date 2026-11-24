/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 22:35:28 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/18 22:36:07 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_hook(int k, t_config *conf)
{
	if (k == ESC)
		close_window(conf);
	if (k == KEY_M)
		conf->mp.enabled = !conf->mp.enabled;
	if (!conf->mp.enabled)
	{
		//movement and camera padding
	}
	return (0);
}

int	close_window(t_config *conf)
{
	mlx_loop_end(conf->mlx.mlx);
	return (0);
}
