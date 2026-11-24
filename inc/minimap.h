/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:16:33 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/24 14:16:55 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
//defines
# define MINIMAP_H
# define MP_WIDTH	1280
# define MP_HEIGHT	720
# define TILE_SIZE	64

//functions
void	render_minimap(t_config *conf);
char	**init_minimap(void);

#endif
