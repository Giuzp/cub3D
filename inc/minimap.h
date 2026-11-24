/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:43:26 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/24 21:43:26 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
//defines
# define MINIMAP_H
# define MP_PERCENT 75
# define TS	64

//functions
void	render_minimap(t_config *conf);
char	**init_minimap(int width, int height);

#endif
