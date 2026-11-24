/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:40:56 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/24 21:41:23 by dcresce          ###   ########.ch       */
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
char	**init_minimap(int width, int height)
{
	char	**minimap;
	int		y;

	minimap = ft_calloc(height + 1, sizeof(char *));
	if (!minimap)
		return (NULL);
	y = 0;
	while (y < height)
	{
		minimap[y] = ft_calloc(width + 1, sizeof(char));
		if (!minimap[y])
		{
			free_split(minimap);
			return (NULL);
		}
		y++;
	}
	return (minimap);
}
