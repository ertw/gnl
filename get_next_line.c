/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <ewilliam@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:26:14 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/16 14:42:18 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		ft_strnapnd(char **old, char **new, size_t len)
{
	char	*tmp;
	size_t	old_len;
	size_t	total_len;

	old_len = *old == NULL
		? 0
		: ft_strlen(*old);
	total_len = *old == NULL
		? len
		: len + old_len;
	tmp = ft_memalloc(sizeof(char) * (total_len + 1));
	if (*old == NULL)
		ft_strcpy(tmp, *new);
	else
	{
		ft_stpncpy(ft_stpcpy(tmp, *old), *new, len);
		ft_strdel(&(*old));
	}
	*old = tmp;
}

static t_tuple	ft_read(const int fd)
{
	char		buf[BUFF_SIZE];
	t_tuple		tuple;

	tuple.len = read(fd, buf, BUFF_SIZE);
	tuple.str = tuple.len > READ_EOF
		? ft_strndup(buf, tuple.len)
		: NULL;
	tuple.pos = 0;
	return (tuple);
}

int				ft_ptrdiff(const void *ptr1, const void *ptr2)
{
	unsigned char	p1;
	unsigned char	p2;

	p1 = (unsigned char)ptr1;
	p2 = (unsigned char)ptr2;
	return (p1 > p2
			? p1 - p2
			: p2 - p1);
}

static int		find_line(const int fd, char **line, char *full_line)
{
	static t_tuple	b;
	char			*nl_ptr;
	char			*tmp;

	full_line = NULL;
	*line = NULL;
	while (1)
	{
		if (b.str)
		{
			if ((nl_ptr = ft_strchr(b.str + b.pos, '\n')))
			{
				tmp = ft_strsub(b.str, b.pos, nl_ptr - &b.str[b.pos]);
				ft_strnapnd(&full_line, &tmp, nl_ptr - &b.str[b.pos]);
				b.pos += 1 + nl_ptr - &b.str[b.pos];
				ft_strdel(&tmp);
				return (!!(*line = full_line));
			}
			else
			{
				tmp = ft_strsub(b.str, b.pos, b.len - b.pos);
				ft_strnapnd(&full_line, &tmp, b.len - b.pos);
				ft_strdel(&tmp);
				b.pos = b.len;
			}
		}
		if (b.len == b.pos)
		{
			ft_strdel(&b.str);
			b = ft_read(fd);
			if (!b.str && full_line && *full_line == '\0')
				return (READ_EOF);
			if (b.len == READ_EOF)
				return (!!(*line = full_line));
		}
	}
}

int				get_next_line(const int fd, char **line)
{
	char			*full_line;

	full_line = NULL;
	return ((!line || fd < 0 || read(fd, full_line, 0) == READ_ERROR)
			? READ_ERROR
			: (find_line(fd, line, full_line)));
}
