/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:26:14 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/31 10:38:06 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		ft_vec(char **s, char c)
{
	char	*tmp;
	size_t	len;

	len = *s == NULL ? 0 : ft_strlen(*s);
	tmp = malloc(sizeof(char) * (len + 2));
	ft_memcpy(tmp, *s, len);
	tmp[len] = c;
	tmp[len + 1] = '\0';
//	free(*s);
	*s = tmp;
}

static t_tuple	ft_read(const int fd)
{
	char		buf[BUFF_SIZE];
	t_tuple		tuple;

	tuple.len = read(fd, buf, BUFF_SIZE);
	tuple.str = tuple.len > 0 ? ft_strndup(buf, tuple.len) : NULL;
	tuple.pos = 0;
	tuple.init = 1;
	return (tuple);
}

int				get_next_line(const int fd, char **line)
{
	char			*full_line;
	static t_tuple	buffer;

	full_line = NULL;
	while (1)
	{
		if (!buffer.init)
			buffer = ft_read(fd);
		if (buffer.len == 0)
			return (0);
		if (buffer.len == -1)
			return (-1);
		while (*(buffer.str) != '\n' && buffer.pos != buffer.len)
		{
			ft_vec(&full_line, *(buffer.str));
			buffer.pos++;
			buffer.str++;
		}
		if (*(buffer.str) == '\n')
		{
			buffer.str++;
			buffer.pos++;
			*line = full_line;
			return (1);
		}
		if (buffer.len == buffer.pos)
		{
//			free(buffer.str);
			buffer.init = 0;
		}
	}

//	full_line = NULL;
//	while (1)
//	{
//		if (!buffer.str)
//		{
//			buffer = ft_read(fd);
//			if (buffer.len == -1)
//				return (-1);
//		}
//		while (*(buffer.str) != '\n' && buffer.pos != buffer.len)
//		{
//			ft_vec(&full_line, *(buffer.str));
//			buffer.pos++;
//			buffer.str++;
//		}
//		if (*(buffer.str) == '\n')
//		{
//			buffer.str++;
//			buffer.pos++;
//		}
//		if (buffer.len == buffer.pos && buffer.len == BUFF_SIZE)
//		{
//			buffer = ft_read(fd);
//		}
//		else
//		{
//			if (full_line)
//				*line = full_line;
//			return (!!full_line);
//		}
//	}
//	return (0);
}
