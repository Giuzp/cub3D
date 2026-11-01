/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:25:56 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/01 18:03:51 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_config	*conf;

	if (argc != 2)
		clean_exit(E_ARGS, ARGS, NULL, NULL);
	conf = get_config(argv[1]);
	init_mlx(conf);
	init_image(conf);
	mlx_put_image_to_window(conf->mlx.mlx, conf->mlx.win,
		conf->mlx.frame.img, 0, 0);
	mlx_key_hook(conf->mlx.win, key_hook, conf);
	mlx_loop_hook(conf->mlx.mlx, render_frame, conf);
	mlx_hook(conf->mlx.win, 17, 0, close_window, conf);
	mlx_loop(conf->mlx.mlx);
	return (0);
}
