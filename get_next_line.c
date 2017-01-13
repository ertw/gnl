/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <ewilliam@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:26:14 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/05 16:52:20 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//static void		ft_vec(char **s, char c)
//{
//	char	*tmp;
//	size_t	len;
//
//	len = *s == NULL
//		? 0
//		: ft_strlen(*s);
//	tmp = malloc(sizeof(c) * (len + 2));
//	ft_memcpy(tmp, *s, len);
//	tmp[len] = c;
//	tmp[len + 1] = '\0';
//	ft_strdel(&(*s));
//	*s = tmp;
//}
//
//static char		*ft_str_realloc(char *ptr, size_t len)
//{
//	char	*new_str;
//
//	if (!(new_str = ft_memalloc(sizeof(char) * len)))
//		return (ptr);
//	return (new_str);
//}

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
	static	t_tuple buffer;
	char	*nl_ptr;

	full_line = NULL;
	*line = NULL;
	while (1)
	{
		if (buffer.str)
		{
			nl_ptr = ft_strchr(&buffer.str[buffer.pos], '\n');
			if (nl_ptr)
			{
				printf("%s\n", ft_strndup(&buffer.str[buffer.pos], nl_ptr - &buffer.str[buffer.pos]));
				buffer.pos = nl_ptr - &buffer.str[buffer.pos];
			}
		}
		if (buffer.pos == buffer.len)
			ft_strdel(&buffer.str);
		if (!buffer.str)
			buffer = ft_read(fd);
		if (buffer.len == 0)
			return (READ_EOF);
	}
}



//		if (buffer.str && buffer.str[buffer.pos] == '\n')
//		{
//			buffer.pos++;
//			return (!!(*line = full_line) ? 1 : 1);
//		}
//		if (buffer.str && buffer.str[buffer.pos])
//			ft_vec(&full_line, buffer.str[buffer.pos++]);
//		if (buffer.str == NULL)
//			buffer = ft_read(fd);
//		if (buffer.len == READ_EOF)
//		{
//			return (full_line
//					? !!(*line = full_line)
//					: READ_EOF);
//		}
//		if (buffer.str[buffer.pos] == '\0')
//		{
//			ft_strdel(&buffer.str);
//			buffer.str = NULL;
//		}


int				get_next_line(const int fd, char **line)
{
	char			*full_line;

	full_line = NULL;
	return ((!line || fd < 0 || read(fd, full_line, 0) == READ_ERROR)
			? READ_ERROR
			: (find_line(fd, line, full_line)));
}
