/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:06:00 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 13:43:56 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CONFIG_H
# define GET_CONFIG_H

# include "cub.h"

//get config from the .cub file
t_config	*get_config(char *map_path);

//file store
t_config	*read_store_cubfile(int fd, char *map_path);
int			crop_isspace(char *line, int i);
void		exit_code_init(t_exit_code *exit_code, int code_error,
				char *message);
int			check_if_path_exist(char *line, int i, t_exit_code *exit_code);
int			check_color(char *line, int i, t_exit_code *exit_code);
int			check_other_identifier(char *line);
int			check_identifier(char *line, int *i, t_exit_code *exit_code);
int			check_map_is_ok(int fd, t_exit_code *exit_code);
char		*trim_line(char *line);
t_config	*config_init(char **buffer, t_exit_code *exit_code);
char		*ft_strndup(char *str, int n);
int			check_all_id(t_check_id *id);

//Map store and validation
char		**store_map(int fd);			//store the map from the .cub file
void		validate_map(char **map, int p_pos[2], char *p_dir);	//check map
int			count_lines(char **map);		//count lines in map
char		**dup_array(char **array);		//duplicates the map for flood fill
bool		check_for_missing_spots(char **map, int *x, int *y);

//HELPER FUNCTIONS TO DESTROY LATER
void		print_map(char **map);

#endif
