/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 15:02:39 by dcresce           #+#    #+#             */
/*   Updated: 2026/10/15 16:17:46 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

void	clean_exit(t_error err, char *msg, t_config *conf, t_exit_code *exit_code);
void	free_and_null(char **str);

#endif
