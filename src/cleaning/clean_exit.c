/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:39:27 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/01 21:42:19 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <string.h>

void	clean_exit(t_error err, char *msg, t_config *conf,
		t_exit_code *exit_code)
{
	int		error_code;
	char	*tmp_msg;

	tmp_msg = msg;
	error_code = err;
	printf("%s\n", tmp_msg);
	if (exit_code)
		free(exit_code);
	if (conf)
		clean_config(conf);
	exit(error_code);
}

void	clean_config(t_config *config)
{
	if (!config)
		return ;
	clean_mlx(&config->mlx);
	if (config->map)
		free_split(config->map);
	free_and_null(&config->path_no);
	free_and_null(&config->path_so);
	free_and_null(&config->path_we);
	free_and_null(&config->path_ea);
	free(config);
}

void	clean_mlx(t_mlx *mlx)
{
	if (!mlx->mlx)
		return ;
	if (mlx->frame.img)
		mlx_destroy_image(mlx->mlx, mlx->frame.img);
	ft_bzero(&mlx->frame, sizeof(mlx->frame));
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	mlx->win = NULL;
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
}
