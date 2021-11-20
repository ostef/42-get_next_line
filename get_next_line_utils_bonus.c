/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:20:22 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/16 17:46:55 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

static void	ft_grow(t_str_builder *b)
{
	long	new_cap;
	char	*new_data;
	long	i;

	new_cap = b->cap * 2 + 8;
	new_data = (char *)malloc (new_cap);
	if (!new_data)
	{
		free (b->data);
		b->data = NULL;
		b->cap = 0;
		b->count = 0;
		return ;
	}
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
	if (!b->data)
	{
		b->cap = 0;
		b->count = 0;
		return ;
	}
	b->cap = cap;
	b->count = 0;
}

void	ft_builder_print_char(t_str_builder *b, char c)
{
	if (b->count >= b->cap)
		ft_grow (b);
	if (b->data)
	{
		b->data[b->count] = c;
		b->count += 1;
	}
}

t_line_reader	*ft_get_reader(t_line_reader **readers, const int fd)
{
	t_line_reader	*result;

	result = *readers;
	while (result)
	{
		if (result->fd == fd)
			return (result);
		result = result->next;
	}
	result = (t_line_reader *)malloc (sizeof (t_line_reader));
	if (!result)
		return (NULL);
	result->prev = NULL;
	result->next = *readers;
	if (result->next)
		result->next->prev = result;
	result->fd = fd;
	result->count = 0;
	result->cursor = 0;
	*readers = result;
	return (result);
}

void	ft_free_reader(t_line_reader **readers, const int fd)
{
	t_line_reader	*reader;

	reader = *readers;
	while (reader)
	{
		if (reader->fd == fd)
			break ;
		reader = reader->next;
	}
	if (!reader)
		return ;
	if (reader->next)
		reader->next->prev = reader->prev;
	if (reader->prev)
		reader->prev->next = reader->next;
	else
		*readers = reader->next;
	free (reader);
}
