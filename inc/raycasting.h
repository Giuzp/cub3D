/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:51:07 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/27 14:51:07 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef enum e_id
{
	E_NO,
	E_SO,
	E_EA,
	E_WE
}	t_id;

// render
void	render_game(t_config *conf);

// backend
void	calculate_dist(t_config *conf, t_column *col, int i);

// frontend
void	render_column(t_config *conf, t_column *col, int i);

#endif
