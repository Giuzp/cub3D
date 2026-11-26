/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:14:38 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 11:20:17 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief	Closes a fd and does a clean exit with error message and exit code
 * 
 * @param[in]	fd			fd that needs to be closed
 * @param[in]	err_code	Error code to return
 * @param[in]	err_msg		Error message to display in the terminal
 * @param[in]	exit_code	Exit code struct to free
 */
void	close_exit_clean(int fd, int err_code, char *err_msg,
	t_exit_code *exit_code)
{
	close(fd);
	clean_exit(err_code, err_msg, 0, exit_code);
}

/**
 * @brief	Does a clean exit, used while reading in a fd
 * 
 * @param[in]	fd			fd used for the reading to close
 * @param[in]	line		Last read line
 * @param[in]	buffer		Buffer used to store the lines
 * @param[in]	exit_code	Exit code struct to free
 */
void	clean_while_read(int fd, char *line, char **buffer,
	t_exit_code *exit_code)
{
	close(fd);
	free(line);
	free_split(buffer);
	if (exit_code->code != 0)
		clean_exit(exit_code->code, exit_code->message, 0, exit_code);
	clean_exit(E_MALLOC, MALLOC, 0, exit_code);
}

/**
 * @brief	Frees and sets to null a pointer
 * 
 * @param[in]	str	Pointer to free
 */
void	free_and_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
