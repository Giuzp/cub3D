/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:19:08 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/24 14:20:57 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_pixel(t_image *frame, int x, int y, int color)
{
	char	*pixel;

	pixel = frame->addr + (y * frame->line_len) + (x * (frame->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_square(t_image *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
