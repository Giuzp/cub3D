/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:57:21 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/19 11:58:30 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief	Initialize minimap array
 * 
 * @return	The allocated minimap array
 * 
 * The caller is responsible for freeing the returned configuration
 */
char	**init_minimap(void)
{
	char	**minimap;
	int		y;

	minimap = ft_calloc(MP_HEIGHT + 1, sizeof(char *));
	if (!minimap)
		return (NULL);
	y = 0;
	while (y < MP_HEIGHT)
	{
		minimap[y] = ft_calloc(MP_WIDTH + 1, sizeof(char));
		if (!minimap[y])
		{
			free_split(minimap);
			return (NULL);
		}
		y++;
	}
	return (minimap);
}
