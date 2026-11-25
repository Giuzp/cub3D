/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 20:18:13 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/25 20:18:22 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
// defines
# define MLX_INIT_H
// keycodes
// arrow buttons
# define UP		65362
# define DN		65364
# define LT		65361
# define RT		65363
// WASD buttons
# define KW		119
# define KA		97
# define KS		115
# define KD		100
// other button
# define ESC	65307
# define KEY_M	109
// dimensions
# define DEFAULT_W 1920
# define DEFAULT_H 1080


// init mlx
void	init_mlx(t_config *conf);
void	init_image(t_config *conf);
int		get_monitor_size(t_mlx *mlx);
// loops
int		render_frame(t_config *conf);
int		key_hook(int k, t_config *conf);
int		close_window(t_config *conf);
// drawing
void	put_pixel(t_image *frame, int x, int y, int color);
void	draw_square(t_image *img, int *pos, int size, int color);

#endif
