/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:02:39 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/20 15:06:50 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

#include "structs.h"
#include "errors.h"

void	clean_exit(t_error err, char *msg, t_config *conf,
			t_exit_code *exit_code);
void	free_and_null(char **str);
void	close_exit_clean(int fd, int err_code, char *err_msg,
			t_exit_code *exit_code);
void	clean_while_read(int fd, char *line, char **buffer,
			t_exit_code *exit_code);
void	clean_config(t_config *config);

#endif
