/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:15:05 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 14:07:47 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void cube_init(t_cube cube)
{
    cube = ft_calloc(sizeof(t_cube), 1)
    if (!cube)
        exit() ;
}

void	get_config(char **argv, t_cube cube)
{
    cube_init(cube);
	read_store_cubfile(argv[1]);
}
