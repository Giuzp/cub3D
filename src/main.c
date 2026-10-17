/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:14:56 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/15 16:18:52 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		clean_exit(E_ARGS, ARGS, (void*)NULL, (void*)NULL);
	get_config(argv[1]);
	return (0);
}
