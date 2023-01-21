/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:03:08 by cbolat            #+#    #+#             */
/*   Updated: 2022/10/26 15:17:12 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalenptr(unsigned long nbr)
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

void	ft_printhexaptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_printhexaptr(n / 16);
		ft_printhexaptr(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar(n - 10 + 'a');
		else
			ft_putchar(n + 48);
	}
}	

int	ft_putptr(unsigned long long p)
{
	int	res;

	res = ft_putstr("0x");
	if (p == 0)
		res += ft_putchar('0');
	else
	{
		ft_printhexaptr(p);
		res += ft_hexalenptr(p);
	}
	return (res);
}
