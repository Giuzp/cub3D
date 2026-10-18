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

int	check_map_is_ok(int fd, t_exit_code *exit_code)
{
	int	i;
	char	*line;
	t_check_id	id[6];

	i = 0;
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
	while (line[0] != '1')
	{
		if (line[0] == 'N')
			id->no_id = true;
		else if (line[0] == 'S')
			id->so_id = true;
		else if (line[0] == 'W')
			id->we_id = true;
		else if (line[0] == 'E')
			id->ea_id = true;
		else if (line[0] == 'F')
			id->f_id = true;
		else if (line[0] == 'C')
			id->c_id = true;
		else if (line[0] != '\n')
		{
			close(fd);
			exit_code_init(exit_code, E_SCENE_W, SCENE_W);
			return (1);
		}
		free(line);
		line = gnl(fd);
		i++;
	}
	close(fd);
	free(line);
	if (id->no_id == false)
	{
		exit_code_init(exit_code, E_WRO_O, WRO_O);
		return(1);
	}
	if (id->so_id == false)
	{
		exit_code_init(exit_code, E_WRO_O, WRO_O);
		return(1);
	}
	if (id->we_id == false)
	{
		exit_code_init(exit_code, E_WRO_O, WRO_O);
		return(1);
	}
	if (id->ea_id == false)
	{
		exit_code_init(exit_code, E_WRO_O, WRO_O);
		return(1);
	}
	if (id->f_id == false)
	{
		exit_code_init(exit_code, E_WRO_O, WRO_O);
		return(1);
	}
	if (id->c_id == false)
	{
		exit_code_init(exit_code, E_WRO_O, WRO_O);
		return(1);
	}
	// a faire un if dans un if dans un if
	return(i);
}

