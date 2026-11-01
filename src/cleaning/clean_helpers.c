/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:35:24 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/01 21:35:24 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	close_exit_clean(int fd, int err_code, char *err_msg,
	t_exit_code *exit_code)
{
close(fd);
clean_exit(err_code, err_msg, 0, exit_code);
}

void	clean_while_read(int fd, char *line, char **buffer,
	t_exit_code *exit_code)
{
close(fd);
free(line);
free_split(buffer);
if (exit_code->code != 0)
	clean_exit(exit_code->code, exit_code->message, 0, exit_code);
clean_exit(E_MALLOC, MALLOC, 0, exit_code);
}

void	free_and_null(char **str)
{
if (*str)
{
	free(*str);
	*str = NULL;
}
}
