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
typedef struct s_vec
{
	size_t	len;
	size_t	size;
	char	*str;
}		t_vec;

t_vec		*ft_vec_new(const char *str, size_t len)
{
	t_vec	*vec;

	vec->len = len;
	--len;
	len |= len >> 1;
	len |= len >> 2;
	len |= len >> 4;
	len |= len >> 8;
	len |= len >> 16;
	++len;
	vec->size = len;
	vec->str = ft_memalloc(vec->size);
	ft_memcpy(vec->str, str, len);
return (vec);
}

t_vec		*ft_vec_cat(t_vec vec, size_t len)
{
	char	*new_str;
	
	if (vec.size - vec.len > len)
		; //copy
	ft_vec_new(
	return (new_str);
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

static int		find_line(const int fd, char **line, char *full_line)
{
	static	t_tuple b;
	char	*nl_ptr;

	full_line = NULL;
	*line = NULL;
	while (1)
	{
		if (b.str && (nl_ptr = ft_strchr(&b.str[b.pos], '\n')))
			return (!!(line = ft_strjoin(full_line, )));
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
