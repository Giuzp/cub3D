/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:04:43 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/01 18:04:47 by dcresce          ###   ########.ch       */
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

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	frame;
}	t_mlx;

typedef struct s_minimap
{
	int		width;			//map size in pixels
	int		height;
	int		tile_size;		//size of a tile in pixels
	//dir
	bool	enabled;		//is minimap displayed?
	char	**minimap;
	char	**discovered;	//Discovered tiles map
}	t_minimap;

typedef struct s_config
{
	// map layout
	char		**map;
	// path to the texture files
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	//floor and ceiling colors in 8-bit RGB
	int			col_f[3];
	int			col_c[3];
	// Player infos
	double		p_pos[2];
	char		p_dir;
	// mlx image data
	t_mlx		mlx;
	// minimap
	t_minimap	mp;
}	t_config;

#endif
