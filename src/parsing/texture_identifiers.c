/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_identifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcresce <dcresce@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:17:13 by dcresce           #+#    #+#             */
/*   Updated: 2026/11/26 22:17:13 by dcresce          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* Checks the complete extension, ignoring trailing line whitespace. */
int	check_extention(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\n'))
		len--;
	if (len < 4)
		return (1);
	return (ft_strncmp(str + len - 4, ".xpm", 4) != 0);
}

/* Validates an identifier and marks it as found. */
int	parse_line_texture(char *str, t_check_id *id)
{
	if (str[0] == 'F' || str[0] == 'C')
	{
		if (str[1] != ' ')
			return (1);
	}
	else if (!check_other_identifier(str) || check_extention(str))
		return (1);
	check_letter(str[0], id);
	return (0);
}
