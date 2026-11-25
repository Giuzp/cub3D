#include "cub.h"

void	init_id(t_check_id *id);
int		check_id(char **line, t_check_id *id, int fd);
int		check_flag_id(t_check_id *id, t_exit_code *exit_code);
void	close_and_free(int fd, char *line);

/*
 * In this function we will check if there is all the information we need
 * before map shows up.
 */
int	check_map_is_ok(int fd, t_exit_code *exit_code)
{
	char		*line;
	t_check_id	id[6];

	init_id(id);
	line = gnl(fd);
	if (!line || line[0] == 1)
	{
		close(fd);
		if (line[0] == 1)
			exit_code_init(exit_code, E_WRO_O, WRO_O);
		else
			exit_code_init(exit_code, E_EMPTY, EMPTY);
		return (1);
	}
	if (check_id(&line, id, fd))
	{
		close_and_free(fd, line);
		exit_code_init(exit_code, E_SCENE_W, SCENE_W);
		return (1);
	}
	close_and_free(fd, line);
	return (check_flag_id(id, exit_code));
}

/*
 * initialisation of our ID struct, all variable are a flag
 */
void	init_id(t_check_id *id)
{
	id->no_id = false;
	id->so_id = false;
	id->we_id = false;
	id->ea_id = false;
	id->f_id = false;
	id->c_id = false;
}

int	check_extention(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (!ext)
		return (1);
	printf("%s\n", ext);
	if (ft_strncmp(ext, ".xpm", 4))
		return (1);
	printf("oui");
	return (0);
}

int	parse_line_texture(char *str, t_check_id *id)
{
	check_letter(str[0], id);
	if (str[0] == 'N' || str[0] == 'S'|| str[0] == 'W' || str[0] == 'E')
	{
		if (check_extention(str))
			return (1);
	}
	return (0);
}

/*
 * everytime an identifier is find a flag up and if not
 * correct identifier we exit.
 */
int	check_id(char **line, t_check_id *id, int fd)
{
	int	i;

	i = 0;
	while (*line[0] != '1')
	{
		if (i > 6)
			return (1);
		if (*line[0] == ' ')
		{
			*line = trim_line(*line); // leak ? check 
			continue ;
		}
		if (*line[0] == 'N' || *line[0] == 'C' || *line[0] == 'F' || *line[0] == 'E' || *line[0] == 'W' || *line[0] == 'S')
		{
			if (parse_line_texture(*line, id))
				return (1);
			i++;
		}
		else if (*line[0] != '\n')
			return (1);
		free_and_null(line);
		*line = gnl(fd);
	}
	return (0);
}

/*
 * function for close fd and free line if needed.
 */
void	close_and_free(int fd, char *line)
{
	close(fd);
	if (line)
		free(line);
}

/*
 * Last check, if all flag are up than means we have all the
 * information before map. If not we initialized exit code struct.
 */
int	check_flag_id(t_check_id *id, t_exit_code *exit_code)
{
	if (id->no_id == true)
	{
		if (id->so_id == true)
		{
			if (id->we_id == true)
			{
				if (id->ea_id == true)
				{
					if (id->f_id == true)
					{
						if (id->c_id == true)
						{
							return (0);
						}
					}
				}
			}
		}
	}
	exit_code_init(exit_code, E_WRO_O, WRO_O);
	return (1);
}
