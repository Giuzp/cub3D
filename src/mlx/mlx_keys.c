/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:07:22 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/01 18:07:34 by dcresce          ###   ########.ch       */
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
	return (0);
}
