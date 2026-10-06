/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:01:05 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 15:36:16 by jturrel          ###   ########.fr       */
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
