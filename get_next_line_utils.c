/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:48:11 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/16 17:47:09 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
