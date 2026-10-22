#include "cub.h"

int	check_color(char *line, int i, t_exit_code *exit_code);
int	check_other_identifier(char *line);
int	check_if_path_exist(char *line, int i, t_exit_code *exit_code);
int	free_array_code_init(char **array, t_exit_code *exit_code);

/*
 * Here we check if the identifier are correct, if not we
 * initialized exit code struct. Depends of the identifier
 * we check the color or if the path of texture exist.
 */

int	check_identifier(char *line, int *i, t_exit_code *exit_code)
{
	if (line[*i] == 'C' || line[*i] == 'F')
		return (check_color(line, *i, exit_code));
	else if (check_other_identifier(line))
		return (/*check_if_path_exist(line, *i, exit_code*/ 0);
	exit_code_init(exit_code, E_SCENE_W, SCENE_W);
	return (1);
}

/*
 * we start by split the numbers composing the colour value
 * then we put them in an array and check line by line
 * if they are not more than 3 line or 3 character.
 */

int	check_color(char *line, int i, t_exit_code *exit_code)
{
	char	**number_array;
	int		array_index;

	array_index = 0;
	i++;
	i = crop_isspace(line, i);
	number_array = ft_split(&line[i], ',');
	if (!number_array || !number_array[1])
		return (free_array_code_init(number_array, exit_code));
	while (number_array[array_index] || array_index > 3)
	{
		if (ft_strlen(number_array[array_index]) > 3)
			return (free_array_code_init(number_array, exit_code));
		array_index++;
	}
	if (array_index != 3)
		return (free_array_code_init(number_array, exit_code));
	free_split(number_array);
	number_array = NULL;
	return (0);
}

/*
 * utils function for free the array and initialized
 * the exit code struct.
 */
int	free_array_code_init(char **array, t_exit_code *exit_code)
{
	free_split(array);
	exit_code_init(exit_code, E_COL_M, COL_M);
	return (1);
}

/*
 * check texture identifier
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

/*
 * function for checking if the path is correct, starting by checking
 * if the path is not a directory, then if is a correct file.
 */
int	check_if_path_exist(char *line, int i, t_exit_code *exit_code)
{
	int	fd;

	i = crop_isspace(line, i);
	fd = open(&line[i], O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		exit_code_init(exit_code, E_OPEN, OPEN);
		return (1);
	}
	fd = open(&line[i], O_RDONLY);
	if (fd < 0)
	{
		exit_code_init(exit_code, E_OPEN, OPEN);
		return (1);
	}
	close(fd);
	return (0);
}
