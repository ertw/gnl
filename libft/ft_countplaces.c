/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countplaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:47:27 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/05 21:55:35 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countplaces(int n, const size_t base)
{
	int places;

	if (n == 0)
		return (1);
	places = 0;
	while (n)
	{
		places++;
		n /= base;
	}
	return (places);
}
