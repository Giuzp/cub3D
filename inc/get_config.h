/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 20:57:22 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/06 20:57:22 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CONFIG_H
# define GET_CONFIG_H

//get config from the .cup file
void	get_config(char *map_path);

//Map store and validation
char	**store_map(int fd);	//store the map from the .cub file
void	validate_map(char **map, int p_pos[2], char *p_dir);	//Launch map check 

#endif
