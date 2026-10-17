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

	(void)exit_code;
	init_id(id);
	line = gnl(fd);
	if (!line || line[0] == 1)
	{
		close(fd);
		if (line[0] == 1)
			clean_exit(E_OPEN, OPEN, NULL, NULL); // change message
		clean_exit(E_OPEN, OPEN, NULL, NULL);
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
			clean_exit(E_OPEN, OPEN, NULL, NULL);
		}
		line = gnl(fd);
		i++;
	}
	close(fd);
	if (id->no_id == false)
		return(1);
	if (id->so_id == false)
		return(1);
	if (id->we_id == false)
		return(1);
	if (id->ea_id == false)
		return(1);
	if (id->f_id == false)
		return(1);
	if (id->c_id == false)
		return(1);
	return(i);
}

