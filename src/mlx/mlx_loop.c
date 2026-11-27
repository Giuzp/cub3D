/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:37:00 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/27 14:37:09 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief	Renders the minimap when it is enabled
 *
 * @param[in]	conf	Config struct with the minimap state
 * @return		0
 */
int	render_frame(t_config *conf)
{
	static bool	mp_rendered = false;

	if (conf->mp.enabled)
	{
		if (!mp_rendered)
		{
			render_minimap(conf);
			mp_rendered = true;
		}
	}
	else
	{
		mp_rendered = false;
		render_game(conf);
	}
	return (0);
}
