/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:07:01 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/01 18:07:01 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int render_frame(t_config *conf)
{

//    if (conf->mp.enabled)
     draw_minimap(conf);
  /*  else
    {
        put_pixel(&conf->mlx.frame, 100, 100, 0x0000FF00);
    */
    mlx_put_image_to_window(conf->mlx.mlx,
        conf->mlx.win, conf->mlx.frame.img, 0, 0);
    return (0);
}