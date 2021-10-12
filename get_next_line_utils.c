#include "get_next_line.h"
#include <stdlib.h>

static void	ft_grow(t_str_builder *b)
{
	long	new_cap;
	char	*new_data;
	long	i;

	new_cap = b->cap * 2 + 8;
	new_data = (char *)malloc (new_cap);
	i = 0;
	while (i < b->count)
	{
		new_data[i] = b->data[i];
		i += 1;
	}
	free (b->data);
	b->cap = new_cap;
	b->data = new_data;
}

void	ft_builder_init(t_str_builder *b, long cap)
{
	b->data = (char *)malloc (cap);
	b->cap = cap;
	b->count = 0;
}

void	ft_builder_print_char(t_str_builder *b, char c)
{
	if (c == '\n')
		return ;
	if (b->count >= b->cap)
		ft_grow (b);
	b->data[b->count] = c;
	b->count += 1;
}
