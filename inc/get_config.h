/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:33:11 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/07 20:33:39 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CONFIG_H
# define GET_CONFIG_H

//get config from the .cup file
void	get_config(char *map_path);

//Map store and validation
char	**store_map(int fd);			//store the map from the .cub file
void	validate_map(char **map, int p_pos[2], char *p_dir);	//check map
int		count_lines(char **map);		//count lines in map
char	**dup_array(char **array);		//duplicates the map for flood fill
bool	check_for_missing_spots(char **map, int *x, int *y);

//HELPER FUNCTIONS TO DESTROY LATER
void	print_map(char **map);

#endif
