/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 21:53:56 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/05 21:55:10 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CONFIG_H
# define GET_CONFIG_H

//get config from the .cup file
void	get_config(char *map_path);

//validate map
char	**store_map(int fd);	//store the map from the .cub file

#endif
