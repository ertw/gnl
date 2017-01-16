/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:20:29 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/02 14:01:32 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# define BUFF_SIZE 1
# define READ_ERROR -1
# define READ_EOF 0

int					get_next_line(const int fd, char **line);

typedef struct		s_tuple
{
	char			*str;
	int				len;
	int				pos;
}					t_tuple;
#endif
