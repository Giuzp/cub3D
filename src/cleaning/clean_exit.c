/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:01:05 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 15:02:06 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	clean_exit(t_error err, char *msg /*, t_config conf, bool clean*/)
{
	/*
	if (clean)
		clean_config(conf);
	*/
	printf("%s\n", msg);
	exit(err);
}
