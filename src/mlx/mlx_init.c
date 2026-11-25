/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:37:35 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/25 18:38:32 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_config *conf)
{
	t_mlx	*mlx;

	mlx = &conf->mlx;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		clean_exit(E_MLX_INIT, MLX_INIT, conf, NULL);
	mlx->screen_x = 0;
	mlx->screen_y = 0;
	mlx->width = DEFAULT_W;
	mlx->height = DEFAULT_H;
	get_monitor_size(mlx);
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "cub3D");
	if (!mlx->win)
		clean_exit(E_WIN_FAIL, WIN_FAIL, conf, NULL);
	XMoveWindow(((t_xvar *)mlx->mlx)->display,
		((t_win_list *)mlx->win)->window, mlx->screen_x, mlx->screen_y);
	XFlush(((t_xvar *)mlx->mlx)->display);
}

void	init_image(t_config *conf)
{
	t_image	*frame;

	frame = &conf->mlx.frame;
	frame->img = mlx_new_image(conf->mlx.mlx, conf->mlx.width,
		conf->mlx.height);
	if (!frame->img)
		clean_exit(E_IMG_FAIL, IMG_FAIL, conf, NULL);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp,
			&frame->line_len, &frame->endian);
	if (!frame->addr)
	{
		mlx_destroy_image(conf->mlx.mlx, frame->img);
		frame->img = NULL;
		clean_exit(E_ADDR_FAIL, ADDR_FAIL, conf, NULL);
	}
}
