/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturrel <jturrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:45:02 by jturrel           #+#    #+#             */
/*   Updated: 2026/11/26 14:45:03 by jturrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	put_data_on_config(char *line, t_config *config, t_exit_code *exit_code);
int	atoi_color_data(char **buffer, char *line, t_config *config,
		t_exit_code *exit_code);
int	essential_data(char *line);
int	put_color_data(char *line, t_config *config, int i, t_exit_code *exit_code);

/**
 * @brief	Creates a config struct from the configuration lines
 *
 * @param[in]	buffer		Array containing the texture and color lines
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		A newly allocated config struct, or NULL on error
 *
 * The caller is responsible for freeing the returned configuration
 */
t_config	*config_init(char **buffer, t_exit_code *exit_code)
{
	int			i;
	t_config	*config;

	i = 0;
	config = NULL;
	config = ft_calloc(1, sizeof(*config));
	if (!config)
	{
		exit_code_init(exit_code, E_MALLOC, MALLOC);
		return (NULL);
	}
	while (buffer[i])
	{
		if (put_data_on_config(buffer[i], config, exit_code))
		{
			clean_config(config);
			return (NULL);
		}
		i++;
	}
	config->p_dir = '\0';
	return (config);
}

/**
 * @brief	Stores a texture path or color in the config struct
 *
 * @param[in]	line		Configuration line to read
 * @param[in,out]	config		Config struct to update
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		0 on success, 1 on error
 */
int	put_data_on_config(char *line, t_config *config, t_exit_code *exit_code)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	i = essential_data(line);
	if (line[0] == 'F' || line[0] == 'C')
		return (put_color_data(line, config, i, exit_code));
	tmp = ft_strdup(line + i);
	if (!tmp)
		return (1);
	if (line[0] == 'N')
		config->path_no = tmp;
	else if (line[0] == 'W')
		config->path_we = tmp;
	else if (line[0] == 'S')
		config->path_so = tmp;
	else if (line[0] == 'E')
		config->path_ea = tmp;
	return (0);
}

/**
 * @brief	Splits and stores the color components
 *
 * @param[in]	line		Line containing the color identifier and values
 * @param[in,out]	config		Config struct to update
 * @param[in]	i			Index of the first color value
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		0 on success, 1 on error
 */
int	put_color_data(char *line, t_config *config, int i, t_exit_code *exit_code)
{
	char	**buffer;

	buffer = ft_split(line + i, ',');
	if (!buffer)
	{
		exit_code_init(exit_code, E_MALLOC, MALLOC);
		return (1);
	}
	if (atoi_color_data(buffer, line, config, exit_code))
		return (free_split(buffer), 1);
	free_split(buffer);
	buffer = NULL;
	return (0);
}

/**
 * @brief	Converts and stores color values between 0 and 255
 *
 * @param[in]	buffer		Array containing the color components
 * @param[in]	line		Line identifying the floor or ceiling color
 * @param[in,out]	config		Config struct to update
 * @param[out]	exit_code	Exit code struct to fill in case of error
 * @return		0 on success, 1 on error
 */
int	atoi_color_data(char **buffer, char *line, t_config *config,
		t_exit_code *exit_code)
{
	int	j;
	int	check;

	j = 0;
	while (buffer[j])
	{
		if (only_numbers(buffer[j], exit_code))
			return (1);
		check = ft_atoi(buffer[j]);
		if (check < 0 || check > 255)
		{
			exit_code_init(exit_code, E_COL_W, COL_W);
			return (1);
		}
		if (line[0] == 'F')
			config->col_f[j] = check;
		else
			config->col_c[j] = check;
		j++;
	}
	return (0);
}

/**
 * @brief	Skips identifier characters and spaces before the data
 *
 * @param[in]	line	Configuration line to read
 * @return		Index where the configuration value begins
 */
int	essential_data(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[0] == ' ')
			while (line[i] != ' ')
				i++;
		if (line[i] == 'N' || line[i] == 'W' || line[i] == 'S'
			|| line[i] == 'E')
			i++;
		else if (line[i] == 'F' || line[i] == 'C' || line[i] == 'A'
			|| line[i] == 'O')
			i++;
		else
			break ;
	}
	while (line[i] == ' ')
		i++;
	return (i);
}
