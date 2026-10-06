/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:16:16 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 15:16:16 by dcresce          ###   ########.ch       */
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
	E_SCENE_W
}	t_error;

//define message for the errors
# define MALLOC		"Error! Failed malloc!"
# define ARGS		"Error! Wrong number of argument!"
# define EXT		"Error! Wrong file extension!"
# define OPEN		"Error! Scene file doesn't extst or can't be open!"
# define PATH_M		"Error! Missing path in scene file!"
# define PATH_W		"Error! Path file doesn't exist or can't be open!"
# define COL_M		"Error! Missing color in scene file!"
# define COL_W		"Error! Wrong color in scene file!"
# define SCENE_W	"Error! Unidentified identifier in scene file!"

#endif
