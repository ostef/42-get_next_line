#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **args)
{
	int		fd;
	char	*line;
	int		res;

	if (argc == 1)
		fd = 0;
	else
		fd = open (args[1], O_RDONLY);
	while (1)
	{
		res = get_next_line (fd, &line);
		printf ("%s\n", line);
		free (line);
		if (res <= 0)
			break ;
	}
}
