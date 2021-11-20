/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:20:42 by soumanso          #+#    #+#             */
/*   Updated: 2021/11/14 21:16:22 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
	int						fd;
	long					count;
	long					cursor;
	char					buff[BUFFER_SIZE];
	struct s_line_reader	*prev;
	struct s_line_reader	*next;
}	t_line_reader;

t_line_reader	*ft_get_reader(t_line_reader **readers, const int fd);
void			ft_free_reader(t_line_reader **readers, const int fd);
void			ft_builder_init(t_str_builder *b, long cap);
void			ft_builder_print_char(t_str_builder *b, char c);
char			*get_next_line(const int fd);

#endif
