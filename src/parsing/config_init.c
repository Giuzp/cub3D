#include "cub.h"
#include <string.h>

int			put_data_on_config(char *line, t_config *config,
				t_exit_code *exit_code);
int			atoi_color_data(char **buffer, char *line, t_config *config,
				t_exit_code *exit_code);
int			essential_data(char *line);
int			put_color_data(char *line, t_config *config, int i,
				t_exit_code *exit_code);

/*

	* this is the main funtion for adding data from our buffer to our main struct "config"
 */
t_config	*config_init(char **buffer, t_exit_code *exit_code)
{
	int			i;
	t_config	*config;

	i = 0;
	config = NULL;
	config = calloc(1, sizeof(*config));
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
	return (config);
}

/*

	* we keep in i the len when there is only the information we wanna keep in the struct
 * then depends on the identifier we add the data in the good variable.
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

/*
 * we split and parse colour data
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

/*
 * this function parse colour values and put it in the good variable struct.
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

/*
 * We skip all the futile data from line.
 */
int	essential_data(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'W' || line[i] == 'S'
			|| line[i] == 'E')
			i++;
		else if (line[i] == 'F' || line[i] == 'C' || line[i] == 'A'
			|| line[i] == 'O')
			i++;
		else if (line[i] == ' ')
			i++;
		else
			break ;
	}
	return (i);
}
