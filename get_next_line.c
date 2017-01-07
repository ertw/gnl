/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:26:14 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/05 16:52:20 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_vec(char **s, char c)
{
	char	*tmp;
	size_t	len;

	len = *s == NULL
		? 0
		: ft_strlen(*s);
	tmp = malloc(sizeof(c) * (len + 2));
	ft_memcpy(tmp, *s, len);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free(*s);
	*s = tmp;
}

static t_tuple	ft_read(const int fd)
{
	char		buf[BUFF_SIZE];
	t_tuple		tuple;

	tuple.len = read(fd, buf, BUFF_SIZE);
	tuple.str = tuple.len > 0
		? ft_strndup(buf, tuple.len)
		: NULL;
	tuple.pos = 0;
	return (tuple);
}

static int		find_line(const int fd, char **line, char *full_line)
{
	static t_tuple buffer;

	while (1)
	{
		if (buffer.str && buffer.str[buffer.pos] == '\n')
		{
			buffer.pos++;
			return (!!(*line = full_line) ? 1 : 1);
		}
		if (buffer.str && buffer.str[buffer.pos])
			ft_vec(&full_line, buffer.str[buffer.pos++]);
		if (buffer.str == NULL)
			buffer = ft_read(fd);
		if (buffer.len == 0)
		{
			return (full_line
					? !!(*line = full_line)
					: 0);
		}
		if (buffer.str[buffer.pos] == '\0')
		{
			free(buffer.str);
			buffer.str = NULL;
		}
	}
}

int				get_next_line(const int fd, char **line)
{
	char			*full_line;

	full_line = NULL;
	return ((!line || fd < 0 || read(fd, full_line, 0) == -1)
			? -1
			: (find_line(fd, line, full_line)));
}
