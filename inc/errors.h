/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:44:35 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/27 20:45:14 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// enum for the errors
typedef enum e_error
{
	E_MALLOC,
	E_ARGS,
	E_EXT,
	E_OPEN,
	E_EMPTY,
	E_PATH_M,
	E_PATH_W,
	E_COL_M,
	E_COL_W,
	E_WRO_O,
	E_SCENE_W,
	E_CHAR_UN,
	E_MULT_P,
	E_NO_P,
	E_EMPTY_L,
	E_OPEN_MAP,
	E_HOLE_MAP,
	E_MLX_INIT,
	E_WIN_FAIL,
	E_IMG_FAIL,
	E_ADDR_FAIL
}	t_error;

typedef struct s_exit_code
{
	int		code;
	char	*message;
}	t_exit_code;

//define message for the errors
# define MALLOC		"Error! Failed malloc!"
# define ARGS		"Error! Wrong number of argument!"
# define EXT		"Error! Wrong file extension!"
# define OPEN		"Error! Scene file doesn't exist or can't be open!"
# define EMPTY 		"Error! Empty file!"
# define PATH_M		"Error! Missing path in scene file!"
# define PATH_W		"Error! Path file doesn't exist or can't be open!"
# define COL_M		"Error! Missing color in scene file!"
# define COL_W		"Error! Wrong color in scene file!"
# define WRO_O 		"Error! Wrong order or missing identifier!"
# define SCENE_W	"Error! Unidentified identifier in scene file!"
# define CHAR_UN	"Error! Unknown char in the map!"
# define MULT_P		"Error! Multiple players in map!"
# define NO_P		"Error! No player in the map!"
# define EMPTY_L	"Error! Empty line in map!"
# define OPEN_MAP	"Error! The map is open!"
# define HOLE_MAP	"Error! The map has a hole!"

// mlx errors
# define MLX_INIT	"Error! MLX failed to initialize!"
# define WIN_FAIL	"Error! Failed to create MLX window!"
# define IMG_FAIL	"Error! Failed to create MLX image!"
# define ADDR_FAIL	"Error! Failed to access image pixel data!"

#endif
