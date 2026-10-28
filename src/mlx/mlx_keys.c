/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:28:40 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/28 18:29:29 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_hook(int k, t_config *conf)
{
	if (k == ESC)
		close_window(conf);
	return (0);
}

int	close_window(t_config *conf)
{
	mlx_loop_end(conf->mlx.mlx);
	return 0;
}