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
//



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

int	ft_ptrdiff(const void *ptr1, const void *ptr2)
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
	static	t_tuple b;
	char	*nl_ptr;
	char	*tmp;

	full_line = ft_strdup("");
	*line = NULL;
	while (1)
	{
		if (b.str)
		{
			nl_ptr = ft_strchr(b.str + b.pos, '\n');
			if (nl_ptr)
			{
				tmp = ft_strsub(b.str, b.pos, (ft_ptrdiff(&b.str[b.pos], nl_ptr)));
				full_line = ft_strjoin(full_line, tmp);
				b.pos += 1 + ft_ptrdiff(&b.str[b.pos], nl_ptr);
				ft_strdel(&tmp);
				*line = full_line;
				return (1);
			}
			else
			{
				tmp = ft_strsub(b.str, b.pos, b.len - b.pos);
				full_line = ft_strjoin(full_line, tmp);
				ft_strdel(&b.str);
			}
		}
		if (b.str == NULL)
		{
			b = ft_read(fd);
			if (b.len == 0)
				return (READ_EOF);
		}
	}
}


//		if (b.str)
//		{
//			nl_ptr = ft_strchr(&b.str[b.pos], '\n');
//			if (nl_ptr)
//			{
//				ft_strnapnd(&full_line, &b.str + b.pos, ft_ptrdiff(b.str + b.pos, nl_ptr));
//				b.pos += ft_ptrdiff(b.str + b.pos, nl_ptr) + 1;
//			}
//		}




//		if (b.str)
//		{
//			nl_ptr = ft_strchr(b.str + b.pos, '\n');
//			if (nl_ptr)
//			{
//				ft_strnapnd(&full_line, &b.str + b.pos, nl_ptr - b.str + b.pos - 1);
//				b.pos += nl_ptr - b.str + b.pos + 1;
//				*line = full_line;
//				if (b.pos == b.len)
//					ft_strdel(&b.str);
//				return (1);
//			}
//			else
//			{
//				ft_strnapnd(&full_line, &b.str + b.pos, b.len - b.pos);
//				ft_strdel(&b.str);
//			}
//			//look for a nl;
//			//	if found, copy from pos to nl
//			//	update pos
//			//else copy from pos to end
//			//	null b.str
//		}
//		if (b.str == NULL)
//		{
//			b = ft_read(fd);
//			if (b.len == 0)
//				return (READ_EOF);
//		}


//		if (b.str && (nl_ptr = ft_strchr(&b.str[b.pos], '\n')))
//		{
////			tmp = ft_strndup(&b.str[b.pos], nl_ptr - &b.str[b.pos]);
//			tmp = ft_strsub(b.str, b.pos, nl_ptr - &b.str[b.pos]);
//			b.pos += (nl_ptr - &b.str[b.pos]) + 1;
//			ft_vec(&full_line, &tmp);
//			ft_strdel(&tmp);
//			return (!!(*line = full_line));
//		}
//		if (b.str == NULL)
//		{
//			b = ft_read(fd);
//			if (b.len == 0)
//				return (READ_EOF);
//		}
//		if (b.pos == b.len)
//			ft_strdel(&(b.str));

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
