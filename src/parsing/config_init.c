#include <string.h>

#include "cub.h"

int	put_data_on_config(char *line, t_config *config, t_exit_code *exit_code);

t_config	*config_init(char **buffer, t_exit_code *exit_code)
{
	int	i;
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

int	essential_data(char *line)
{
	int	i;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'W' || line[i] == 'S' || line[i] == 'E')
			i++;
		else if (line[i] == 'F' || line[i] == 'C' || line[i] == 'A' || line[i] == 'O')
			i++;
		else if (line[i] == ' ')
			i++;
		else
			break ;
	}
	return (i);
}

int	put_color_data(char *line, t_config *config, int i, t_exit_code *exit_code)
{
	char	**buffer;
	int	j;
	int	check;

	j = 0;
	buffer = ft_split(line + i, ',');
	if (!buffer)
	{
		exit_code_init(exit_code, E_MALLOC, MALLOC);
		return (1);
	}
	while (buffer[j])
	{
		check = ft_atoi(buffer[j]);
		if (check < 0 || check > 255)
		{
			free_split(buffer);
			exit_code_init(exit_code, E_COL_W, COL_W);
			return (1);
		}
		if (line[0] == 'F')
			config->col_f[j] = check;
		else
			config->col_c[j] = check;
		j++;
	}
	free_split(buffer);
	buffer = NULL;
	return (0);
}

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