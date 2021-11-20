/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:19:51 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/18 07:51:32 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static long	ft_read(t_line_reader *r)
{
	if (r->cursor == r->count)
	{
		r->count = read (r->fd, r->buff, BUFFER_SIZE);
		r->cursor = 0;
	}
	return (r->count);
}

static int	ft_copy_buff(t_line_reader *r, t_str_builder *b)
{
	while (r->cursor < r->count)
	{
		ft_builder_print_char (b, r->buff[r->cursor]);
		r->cursor += 1;
		if (b->data && b->data[b->count - 1] == '\n')
		{
			ft_builder_print_char (b, 0);
			return (1);
		}
	}
	return (0);
}

char	*get_next_line(const int fd)
{
	static t_line_reader	*readers;
	t_line_reader			*reader;
	t_str_builder			builder;

	reader = ft_get_reader (&readers, fd);
	ft_builder_init (&builder, 100);
	while (reader && builder.data)
	{
		if (ft_copy_buff (reader, &builder))
			return (builder.data);
		ft_read (reader);
		if (reader->count == 0)
		{
			if (builder.count == 0)
				break ;
			ft_free_reader (&readers, fd);
			ft_builder_print_char (&builder, 0);
			return (builder.data);
		}	
		else if (reader->count < 0)
			break ;
	}
	free (builder.data);
	ft_free_reader (&readers, fd);
	return (NULL);
}
