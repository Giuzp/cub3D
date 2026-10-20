/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:09:08 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/20 15:07:03 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_check_id
{
	bool	no_id;
	bool	so_id;
	bool	we_id;
	bool	ea_id;
	bool	f_id;
	bool	c_id;
}			t_check_id;

typedef struct s_config
{
	// map layout
	char	**map;
	// path to the texture files
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	// floor and cealing colors in 8-bit RGB
	int		col_f[3];
	int		col_c[3];
	// Player infos
	float	p_pos[2];
	char	dir;
}			t_config;

#endif
