/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:12:24 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 22:13:13 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_color(char *line, int i, t_exit_code *exit_code);
int	check_other_identifier(char *line);
int	check_if_path_exist(char *line, int i, t_exit_code *exit_code);
int	free_array_code_init(char **array, t_exit_code *exit_code);

/**
 * @brief	Checks the configuration identifier and its color data
 *
 * @param[in]	line		Configuration line to check
 * @param[in]	i			Index of the identifier in the line
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		0 on success, 1 on error
 */
int	check_identifier(char *line, int *i, t_exit_code *exit_code)
{
	if (line[*i] == 'C' || line[*i] == 'F')
		return (check_color(line, *i, exit_code));
	else if (check_other_identifier(line))
		return (check_if_path_exist(line, *i, exit_code));
	exit_code_init(exit_code, E_SCENE_W, SCENE_W);
	return (1);
}

/**
 * @brief	Checks the number and length of the color components
 *
 * @param[in]	line		Line containing the color identifier and values
 * @param[in]	i			Index of the color identifier
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		0 on success, 1 on error
 */
int	check_color(char *line, int i, t_exit_code *exit_code)
{
	char	**number_array;
	int		array_index;

	array_index = 0;
	i++;
	i = crop_isspace(line, i);
	if (!check_color_commas(&line[i]))
	{
		exit_code_init(exit_code, E_COL_M, COL_M);
		return (1);
	}
	number_array = ft_split(&line[i], ',');
	if (!number_array || !number_array[1])
		return (free_array_code_init(number_array, exit_code));
	while (array_index < 3 && number_array[array_index])
	{
		if (ft_strlen(number_array[array_index]) > 3)
			return (free_array_code_init(number_array, exit_code));
		array_index++;
	}
	if (array_index != 3 || number_array[array_index])
		return (free_array_code_init(number_array, exit_code));
	free_split(number_array);
	number_array = NULL;
	return (0);
}

/**
 * @brief	Frees the array and sets the color format error
 *
 * @param[in]	array		Allocated array to free
 * @param[out]	exit_code	Exit code struct to fill
 * @return		1
 */
int	free_array_code_init(char **array, t_exit_code *exit_code)
{
	if (!array)
	{
		exit_code_init(exit_code, E_MALLOC, MALLOC);
		return (1);
	}
	free_split(array);
	exit_code_init(exit_code, E_COL_M, COL_M);
	return (1);
}

/**
 * @brief	Checks if the line starts with a texture identifier
 *
 * @param[in]	line	Configuration line to check
 * @return		1 if the identifier is recognized, 0 otherwise
 */
int	check_other_identifier(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	else if (!ft_strncmp(line, "SO ", 3))
		return (1);
	else if (!ft_strncmp(line, "WE ", 3))
		return (1);
	else if (!ft_strncmp(line, "EA ", 3))
		return (1);
	return (0);
}

/**
 * @brief	Checks that the texture path is a readable file
 *
 * @param[in]	line		Line containing the texture path
 * @param[in]	i			Index where the path or leading spaces begin
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		0 on success, 1 on error
 */
int	check_if_path_exist(char *line, int i, t_exit_code *exit_code)
{
	int		fd;

	i = crop_isspace(line, i + 2);
	fd = open(line + i, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		exit_code_init(exit_code, E_OPEN, OPEN);
		return (1);
	}
	fd = open(line + i, O_RDONLY);
	if (fd < 0)
	{
		exit_code_init(exit_code, E_OPEN, OPEN);
		return (1);
	}
	close(fd);
	return (0);
}
