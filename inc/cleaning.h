/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:43:16 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/01 21:43:16 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

# include "errors.h"
# include "structs.h"

void	clean_exit(t_error err, char *msg, t_config *conf,
			t_exit_code *exit_code);
void	free_and_null(char **str);
void	close_exit_clean(int fd, int err_code, char *err_msg,
			t_exit_code *exit_code);
void	clean_while_read(int fd, char *line, char **buffer,
			t_exit_code *exit_code);
void	clean_config(t_config *config);
int		only_numbers(char *str, t_exit_code *exit_code);
void	clean_mlx(t_mlx *mlx);

#endif
