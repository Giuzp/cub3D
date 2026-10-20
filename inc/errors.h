/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:22:15 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/20 15:06:56 by jturrel          ###   ########.fr       */
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
	E_SCENE_W
}			t_error;

typedef struct s_exit_code
{
	int		code;
	char	*message;
}			t_exit_code;

// define message for the errors
# define MALLOC "Error! Failed malloc!"
# define ARGS "Error! Wrong number of argument!"
# define EXT "Error! Wrong file extension!"
# define OPEN "Error! Scene file doesn't exist or can't be open!"
# define EMPTY "Error! Empty file!"
# define PATH_M "Error! Missing path in scene file!"
# define PATH_W "Error! Path file doesn't exist or can't be open!"
# define COL_M "Error! Missing color in scene file!"
# define COL_W "Error! Wrong color in scene file!"
# define WRO_O "Error! Wrong order or missing identifier!"
# define SCENE_W "Error! Unidentified identifier in scene file!"

#endif
