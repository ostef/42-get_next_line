#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_set_fd(t_line_reader *r, int new_fd)
{
	if (new_fd != r->fd)
	{
		r->cursor = 0;
		r->count = 0;
		r->fd = new_fd;
	}
}

static long	ft_read(t_line_reader *r)
{
	if (r->cursor == r->count)
	{
		r->count = read (r->fd, r->buff, BUFFER_SIZE);
		r->cursor = 0;
	}
	return (r->count);
}

int	get_next_line(const int fd, char **line)
{
	static t_line_reader	reader;
	t_str_builder			builder;

	ft_set_fd (&reader, fd);
	ft_builder_init (&builder, 100);
	while (1)
	{
		while (reader.cursor < reader.count)
		{
			if (reader.buff[reader.cursor] == '\n')
			{
				reader.cursor += 1;
				ft_builder_print_char (&builder, 0);
				*line = builder.data;
				return (1);
			}
			ft_builder_print_char (&builder, g_reader.buff[g_reader.cursor]);
			g_reader.cursor += 1;
		}
		if (ft_read (&g_reader) <= 0)
		{
			free (builder.data);
			return (g_reader.count);
		}
	}
	return (-1);
}
