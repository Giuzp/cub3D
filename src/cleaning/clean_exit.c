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

#include "cub.h"

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

	error_code  = err;
	printf("%s\n", msg);
	if (exit_code)
		free(exit_code);
	if (conf)
		free(conf);
	exit(error_code);
}
