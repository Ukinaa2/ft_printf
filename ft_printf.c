/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:57:12 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/07 13:57:04 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list args;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i] && str)
	{
		if (str[i] == '%')
		{
			str++;
			if (str[i] == 'c')
				j += ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 's')
				j += ft_putstr_fd(va_arg(args, char *), 1);
			else if (str[i] == 'p')
				j += ft_puthex_fd(va_arg(args, int), "0123456789abcdef", 1);
			else if (str[i] == 'd')
				va_arg(args, int);
			else if (str[i] == 'i')
				j += ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'u')
				va_arg(args, unsigned int);
			else if (str[i] == 'x')
				j += ft_puthex_fd(va_arg(args, int), "0123456789abcdef", 1);
			else if (str[i] == 'X')
				j += ft_puthex_fd(va_arg(args, int), "0123456789ABCDEF", 1);
			else
				j += ft_putchar_fd(str[i], 1);
		}
		else
			j += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i + j);
}

int	main(void)
{
	int	i;
	int	j;

	i = ft_printf("%i | %x | %X | %p\n", 42, 134302, 134302, &i);
	j = printf("%i | %x | %X | %p\n", 42, 134302, 134302, &i);
	ft_printf("%i | %i\n", i, j);
	printf("%i | %i\n", i, j);
	return (0);
}
