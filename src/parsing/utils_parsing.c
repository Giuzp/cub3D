#include "cub.h"

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

void	exit_code_init(t_exit_code *exit_code, int code_error, char *message)
{
	exit_code->code = code_error;
	exit_code->message = message;
}

int	crop_isspace(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

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
