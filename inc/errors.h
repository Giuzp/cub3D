/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:46:26 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 21:47:00 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

//enum for the errors
typedef enum e_error
{
	E_MALLOC,
	E_ARGS,
	E_EXT,
	E_OPEN,
	E_PATH_M,
	E_PATH_W,
	E_COL_M,
	E_COL_W,
	E_SCENE_W,
	E_CHAR_UN,
	E_MULT_P,
	E_NO_P,
	E_EMPTY_L,
	E_OPEN_MAP,
	E_HOLE_MAP
}	t_error;

//define message for the errors
# define MALLOC		"Error! Failed malloc!"
# define ARGS		"Error! Wrong number of argument!"
# define EXT		"Error! Wrong file extension!"
# define OPEN		"Error! Scene file doesn't exist or can't be open!"
# define PATH_M		"Error! Missing path in scene file!"
# define PATH_W		"Error! Path file doesn't exist or can't be open!"
# define COL_M		"Error! Missing color in scene file!"
# define COL_W		"Error! Wrong color in scene file!"
# define SCENE_W	"Error! Unidentified identifier in scene file!"
# define CHAR_UN	"Error! Unknown char in the map!"
# define MULT_P		"Error! Multiple players in map!"
# define NO_P		"Error! No player in the map!"
# define EMPTY_L	"Error! Empty line in map!"
# define OPEN_MAP	"Error! The map is open!"
# define HOLE_MAP	"Error! The map has a hole!"

#endif
