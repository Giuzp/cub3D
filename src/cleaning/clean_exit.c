/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:01:05 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/15 16:17:20 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "cub.h"

void close_exit_clean(int fd,int err_code, char* err_msg, t_exit_code *exit_code)
{
	close(fd);
	clean_exit(err_code, err_msg, 0,exit_code);
}

void clean_while_read(int fd, char *line, char **buffer, t_exit_code *exit_code)
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
	if(*str)
	{
		free(*str);
		*str = NULL;
	}
	return ;
}

void	clean_exit(t_error err, char *msg,  t_config *conf, t_exit_code *exit_code)
{
	int	error_code;
	char	*tmp_msg;

	tmp_msg = msg;
	error_code  = err;
	printf("%s\n", tmp_msg);
	if (exit_code)
		free(exit_code);
	if (conf)
		free(conf);
	exit(error_code);
}
