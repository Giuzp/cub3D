/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 20:24:46 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/15 15:41:23 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CONFIG_H
# define GET_CONFIG_H


#include "errors.h"

void	get_config(char *map_path);
int    read_store_cubfile(int fd, char *map_path);
int crop_isspace(char *line, int i);
void exit_code_init(t_exit_code *exit_code,int code_error, char *message);
int check_if_path_exist(char *line, int i, t_exit_code *exit_code);
int check_color(char *line, int i, t_exit_code *exit_code);
int check_other_identifier(char *line);
int check_identifier(char *line, int *i, t_exit_code *exit_code);
int	check_map_is_ok(int fd, t_exit_code *exit_code);

#endif
