/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:25:15 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 11:30:12 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief	Draws a pixel to the window
 * 
 * @param[in]	frame	Window where the pixel has to be drawn
 * @param[in]	x		X coordinate of the pixel
 * @param[in]	y		Y coordinate of the pixel
 * @param[in]	color	Color of the pixel
 */
void	put_pixel(t_image *frame, int x, int y, int color)
{
	char	*pixel;

	pixel = frame->addr + (y * frame->line_len) + (x * (frame->bpp / 8));
	*(unsigned int *)pixel = color;
}

/**
 * @brief	Draws a square to the window
 * 
 * @param[in]	img		Window where the pixel has to be drawn
 * @param[in]	pos		Coordinates of the square
 * @param[in]	size	Dimension of the square
 * @param[in]	color	Color of the square	
 */
void	draw_square(t_image *img, int *pos, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(img, pos[0] + j, pos[1] + i, color);
			j++;
		}
		i++;
	}
}
