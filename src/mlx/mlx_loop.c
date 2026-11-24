/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 22:32:10 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/24 11:29:51 by jturrel          ###   ########.fr       */
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

void put_pixel(t_image *frame, int x, int y, int color)
{
    char *pixel;

    pixel = frame->addr + (y * frame->line_len) + (x * (frame->bpp / 8));
    *(unsigned int *)pixel = color;
}

void draw_square(t_image *img, int x, int y, int size, int color)
{
    int i;
    int j;

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

void draw_minimap(t_config *conf)
{
    int x;
    int y;
    int size;

    size = 35; //conf->mp.tile_size;
    y = 0;
    while (conf->map[y])
    {
        x = 0;
        while (conf->map[y][x])
        {
            if (conf->map[y][x] == '1')
                draw_square(&conf->mlx.frame,
                    x * size, y * size, size, 0x00808080);
            else if (conf->map[y][x] == '0')
                draw_square(&conf->mlx.frame,
                    x * size, y * size, size, 0x00FFFFFF);
            x++;
        }
        y++;
    }
    draw_square(&conf->mlx.frame, 365, 55, 10, 0x00FF0000);
    /*draw_square(&conf->mlx.frame,
    conf->p_pos[0] * size,
    conf->p_pos[1] * size,
    4, 0x00FF0000);*/
}
