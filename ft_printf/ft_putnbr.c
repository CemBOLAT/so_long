/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:04:22 by cbolat            #+#    #+#             */
/*   Updated: 2022/10/26 15:17:05 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int		i;
	char	*s;

	i = 0;
	if (nbr == 0)
	{
		(write(1, "0", 1));
		return (1);
	}
	s = ft_itoa(nbr);
	i = ft_putstr(s);
	free(s);
	return (i);
}
