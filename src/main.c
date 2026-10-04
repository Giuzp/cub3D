/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:13:48 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/02 16:14:13 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
    t_cube  cube;

	if (argc != 2)
        return (1);
    //check .cub extension
    //check if file exist
    get_config(argvm cube);

}
