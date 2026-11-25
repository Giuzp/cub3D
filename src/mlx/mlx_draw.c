/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 20:17:28 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/25 20:17:41 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_pixel(t_image *frame, int x, int y, int color)
{
	char	*pixel;

	pixel = frame->addr + (y * frame->line_len) + (x * (frame->bpp / 8));
	*(unsigned int *)pixel = color;
}

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
