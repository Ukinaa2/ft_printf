/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:57:12 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/10 13:02:21 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list args;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				i += ft_putchar_fd(va_arg(args, int), 1);
			else if (*str == 's')
				i += ft_putstr_fd(va_arg(args, char *), 1);
			else if (*str == 'p')
			{
				i += ft_putstr_fd("0x", 1);
				i += ft_puthex_fd(va_arg(args, unsigned long), "0123456789abcdef", 1);
			}
			else if (*str == 'd')
				i += ft_putnbr_fd(va_arg(args, int), 1);
			else if (*str == 'i')
				i += ft_putnbr_fd(va_arg(args, int), 1);
			else if (*str == 'u')
				i += ft_putunbr_fd(va_arg(args, unsigned int), 1);
			else if (*str == 'x')
				i += ft_puthex_fd(va_arg(args, unsigned int), "0123456789abcdef", 1);
			else if (*str == 'X')
				i += ft_puthex_fd(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
			else if (*str == '%')
				i += ft_putchar_fd('%', 1);
		}
		else
			i += ft_putchar_fd(*str, 1);
		str++;
	}
	return (i);
}
