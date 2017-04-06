/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <ewilliam@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:26:14 by ewilliam          #+#    #+#             */
/*   Updated: 2017/02/07 10:46:59 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static int		find_line(const int fd, char **line, char *full_line)
{
	static t_tuple	b;

	while (1)
	{
		if (b.str && (b.nl_ptr = ft_strchr(b.str + b.pos, '\n')))
		{
			ft_strnjoin(&full_line, b.str + b.pos, b.nl_ptr - (b.str + b.pos));
			b.pos += 1 + b.nl_ptr - &b.str[b.pos];
			return (!!(*line = full_line));
		}
		if (b.str)
		{
			ft_strnjoin(&full_line, b.str + b.pos, b.len - b.pos);
			b.pos = b.len;
		}
		if (b.len == b.pos)
		{
			ft_strdel(&b.str);
			b = ft_read(fd);
			if (!b.str && full_line && *full_line == '\0')
				return (READ_EOF);
			if (b.len == 0)
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
