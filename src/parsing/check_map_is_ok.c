#include "cub.h"

typedef struct s_check_id {
	bool	no_id;
	bool	so_id;
	bool	we_id;
	bool	ea_id;
	bool	f_id;
	bool	c_id;
} t_check_id;

void	init_id(t_check_id *id)
{
	id->no_id = false;
	id->so_id = false;
	id->we_id = false;
	id->ea_id = false;
	id->f_id = false;
	id->c_id = false;
}

int	check_id(char **line, t_check_id *id, int fd)
{
	while (*line[0] != '1')
	{
		if (*line[0] == 'N')
			id->no_id = true;
		else if (*line[0] == 'S')
			id->so_id = true;
		else if (*line[0] == 'W')
			id->we_id = true;
		else if (*line[0] == 'E')
			id->ea_id = true;
		else if (*line[0] == 'F')
			id->f_id = true;
		else if (*line[0] == 'C')
			id->c_id = true;
		else if (*line[0] != '\n')
			return (1);
		free_and_null(line);
		*line = gnl(fd);
	}
	return (0);
}

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
	return(1);
}

void	close_and_free(int fd, char *line)
{
	close(fd);
	if (line)
		free(line);
}

int	check_map_is_ok(int fd, t_exit_code *exit_code)
{
	char	*line;
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
	return(check_flag_id(id, exit_code));
}

