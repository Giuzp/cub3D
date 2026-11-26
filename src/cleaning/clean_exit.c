/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:07:33 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 11:14:08 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <string.h>

/**
 * @brief	Cleans the config and exit code structs and exits with the correct
 * 			message and exit code
 * 
 * @param[in]	err			The exit code
 * @param[in]	msg			The message to display in the terminal
 * @param[in]	conf		The config to free
 * @param[in]	exit_code	The exit code struct to free
 */
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

/**
 * @brief	Cleans the config struct
 * 
 * @param[in]	config	Config struct to free
 */
void	clean_config(t_config *config)
{
	if (!config)
		return ;
	clean_mlx(&config->mlx);
	if (config->map)
		free_split(config->map);
	clean_minimap(&config->mp);
	free_and_null(&config->path_no);
	free_and_null(&config->path_so);
	free_and_null(&config->path_we);
	free_and_null(&config->path_ea);
	free(config);
}

/**
 * @brief	Cleans the mlx struct
 * 
 * @param[in]	mlx	Mlx struct to free
 */
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

/**
 * @brief	Cleans the minimap struct
 * 
 * @param[in]	mp	Minimap to free
 */
void	clean_minimap(t_minimap *mp)
{
	if (!mp)
		return ;
	if (mp->discovered)
		free_split(mp->discovered);
	if (mp->minimap)
		free_split(mp->minimap);
}
