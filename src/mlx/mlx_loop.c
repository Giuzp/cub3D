/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:34:53 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/24 11:34:53 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		//display game
	}
	return (0);
}
