/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:57:12 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 13:36:47 by gguedes          ###   ########.fr       */
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
				i += ft_putstr_fd(ft_itoa_base(va_arg(args, long long), 16), 1);
			}
			else if (*str == 'd')
				i += ft_putstr_fd(ft_itoa_base(va_arg(args, int), 10), 1);
			else if (*str == 'i')
				i += ft_putstr_fd(ft_itoa_base(va_arg(args, int), 10), 1);
			else if (*str == 'u')
				i += ft_putstr_fd(ft_itoa_base(va_arg(args, unsigned int), 10), 1);
			else if (*str == 'x')
				i += ft_putstr_fd(ft_itoa_base(va_arg(args, long long), 16), 1);
			else if (*str == 'X')
				i += ft_putstr_fd(ft_strmapi(ft_itoa_base(va_arg(args, long long), 16), &ft_toupper), 1);
			else if (*str == '%')
				i += ft_putchar_fd('%', 1);
		}
		else
			i += ft_putchar_fd(*str, 1);
		str++;
	}
	return (i);
}
