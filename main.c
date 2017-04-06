/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 10:31:56 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/28 14:45:35 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	status;
	char	*line;
	int	fd;

	line = NULL;
	fd = (argc == 2)
		? open(argv[1], O_RDONLY)
		: 0;
//	argc = 0;
//	argv = 0;
//	fd = open("/nfs/2016/e/ewilliam/Documents/gnl/test3.txt", O_RDONLY);
	while ((status = get_next_line(fd, &line)) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	ft_putnbr(status);
	ft_putendl(line);
	return (0);
}
