/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:26:14 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/28 13:40:06 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_vec(char **s, char c)
{
	char	*tmp;
	size_t	len;

	len = *s == NULL ? 0 : ft_strlen(*s);
//	printf("len: %zu\n", len);
	tmp = malloc(sizeof(char) * (len + 2));
	ft_memcpy(tmp, *s, len);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free(*s);
	*s = tmp;
//	printf("*s: %s\n", *s);
}

static t_tuple ft_read(const int fd)
{
	char		buf[BUFF_SIZE];
	t_tuple		tuple;

	tuple.n = read(fd, buf, BUFF_SIZE);
	tuple.s = tuple.n >= 0 ? ft_strndup(buf, tuple.n) : NULL;
	tuple.p = 0;
//	printf("s: %s\n", tuple.s);
	return (tuple);
}

int		get_next_line(const int fd, char **line)
{
	char		*full_line;
	static t_tuple	buffer;
	
	full_line = NULL;
	if (!buffer.s)
		buffer = ft_read(fd);
	while (*(buffer.s) != '\n' && buffer.n > 0)
	{
		if (buffer.p == buffer.n)
		{
			buffer.p = 0;
			buffer = ft_read(fd);
		}
		ft_vec(&full_line, *(buffer.s));
		buffer.p++;
		buffer.s++;
//		printf("inner: %d\n", !!full_line);
	}
	buffer.s++;
	*line = full_line;
	return (EOF);
}
