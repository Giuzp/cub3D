/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:56:56 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 14:57:30 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief	Trims spaces from both ends of an allocated line
 *
 * @param[in]	line	Allocated line, freed by this function
 * @return		A newly allocated trimmed line, or NULL on allocation failure
 *
 * The caller is responsible for freeing the returned line
 */
char	*trim_line(char *line)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(line);
	free_and_null(&line);
	line = ft_strtrim(tmp, " ");
	free_and_null(&tmp);
	return (line);
}

/**
 * @brief	Stores an error code and message in the exit code struct
 *
 * @param[out]	exit_code	Exit code struct to fill
 * @param[in]	code_error	Error code to store
 * @param[in]	message		Error message to store without copying
 */
void	exit_code_init(t_exit_code *exit_code, int code_error, char *message)
{
	exit_code->code = code_error;
	exit_code->message = message;
}

/**
 * @brief	Skips spaces from the given index in a line
 *
 * @param[in]	line	Line to read
 * @param[in]	i		Starting index
 * @return		Index of the first character that is not a space
 */
int	crop_isspace(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

/**
 * @brief	Checks that the string contains only decimal digits
 *
 * @param[in]	str			String to check
 * @param[out]	exit_code	Exit code struct to fill on an invalid character
 * @return		0 if all characters are digits, 1 otherwise
 */
int	only_numbers(char *str, t_exit_code *exit_code)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			exit_code_init(exit_code, E_COL_W, COL_W);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * n + 1);
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
