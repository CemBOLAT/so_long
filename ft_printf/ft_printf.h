/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:29:14 by cbolat            #+#    #+#             */
/*   Updated: 2022/10/26 15:23:06 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa(int nbr);
int		ft_putchar(char c);
int		ft_format(const char c, va_list args);
int		ft_putnbr(int nbr);
int		ft_putstr(const char *c);
int		ft_putnbr(int nbr);
int		ft_print_unsigned(unsigned int n);
int		ft_putnbrhexa(char c, unsigned int nbr);
int		ft_putptr(unsigned long long nbr);
int		ft_hexalen(unsigned int nbr);
void	ft_printhexaptr(unsigned long long n);
int		ft_hexalenptr(unsigned long nbr);
int		countui(unsigned int n);
char	*ft_itoaui(unsigned int n);

#endif
