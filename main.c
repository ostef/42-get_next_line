#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **args)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else
		fd = open (args[1], O_RDONLY);
	while (get_next_line (fd, &line) > 0)
	{
		printf ("%s\n", line);
		free (line);
	}
}
