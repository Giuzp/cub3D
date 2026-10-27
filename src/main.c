/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:08:16 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/27 21:09:16 by dcresce          ###   ########.ch       */
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
	return (0);
}
