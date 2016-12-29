/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:20:29 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/28 15:49:34 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/libft.h"
# define BUFF_SIZE 32
# define EOF 0
# define ERR -1
# define READ 1
int	get_next_line(const int fd, char **line);

typedef struct		s_tuple
{
	char		*s;
	int		n;
	int		p;
}			t_tuple;
#endif
