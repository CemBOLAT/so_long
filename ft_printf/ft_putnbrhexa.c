/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:51:21 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/10 01:07:11 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned int nbr)
{
	int	res;

	res = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		res++;
	}
	return (res);
}

void	ft_printhexa(unsigned int n, char c)
{
	if (n >= 16)
	{
		ft_printhexa(n / 16, c);
		ft_printhexa(n % 16, c);
	}
	else if (n <= 9)
		ft_putchar(n + 48);
	else if (c == 'x' && n >= 10 && n <= 15)
		ft_putchar(n + 87);
	else if (c == 'X' && n >= 10 && n <= 15)
		ft_putchar(n + 55);
}

int	ft_putnbrhexa(char c, unsigned int nbr)
{
	int	res;

	res = ft_hexalen(nbr);
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_printhexa(nbr, c);
	return (res);
}
