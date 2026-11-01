/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 17:50:23 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/01 17:50:23 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MLX_INIT_H
// defines
# define MLX_INIT_H
// window size
# define LENGTH	1280
# define WIDTH	720
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

// init mlx
void	init_mlx(t_config *conf);
void	init_image(t_config *conf);
// loops
int		render_frame(t_config *conf);
int		key_hook(int k, t_config *conf);
int		close_window(t_config *conf);


#endif
