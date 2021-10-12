#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_str_builder
{
	long	cap;
	long	count;
	char	*data;
}	t_str_builder;

typedef struct s_line_reader
{
	int		fd;
	long	count;
	long	cursor;
	char	buff[BUFFER_SIZE];
}	t_line_reader;

void	ft_builder_init(t_str_builder *b, long cap);
void	ft_builder_print_char(t_str_builder *b, char c);
int		get_next_line(const int fd, char **line);

#endif
