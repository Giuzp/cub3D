/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 06/10/2026 14:00:52 by dcresce           #+#    #+#             */
/*   Updated: 06/10/2026 14:01:46 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H$
# define STRUCTS_H

typedef struct	conf
{
	//map layout
	char	**map;
	//path to the texture files
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	//floor and cealing colors in 8-bit RGB
	int		col_f[3];
	int		col_c[3];
	//Player infos
	float	p_pos[2];
	char	dir;
};


#endif
