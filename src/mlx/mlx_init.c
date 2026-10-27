/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:03:59 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/27 21:03:59 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_config *conf)
{
	t_mlx *mlx = &(conf->mlx);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		clean_exit(E_MLX_INIT, MLX_INIT, conf, NULL);
	mlx->win = mlx_new_window(mlx->win, LENGTH, WIDTH, "cub3D");
	if (!mlx->win)
		clean_exit(E_WIN_FAIL, WIN_FAIL, conf, NULL);
}

void	init_image(t_config *conf)
{
	t_image *frame;

	frame = &conf->mlx.frame;
	frame->img = mlx_new_image(conf->mlx.mlx, LENGTH, WIDTH);
	if(!frame->img)
		clean_exit(E_IMG_FAIL, IMG_FAIL, conf, NULL);
	frame->addr = mlx_get_data_addr(frame->img, frame->bpp,
		frame->line_len, frame->endian);
	if (!frame->addr)
	{
		mlx_destroy_image(conf->mlx.mlx, frame->img);
		frame->img = NULL;
		clean_exit(E_ADDR_FAIL, ADDR_FAIL, conf, NULL);
	}
}