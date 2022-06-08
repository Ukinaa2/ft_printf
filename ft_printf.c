/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:57:12 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/08 14:03:02 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list args;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			str++;
			if (str[i] == 'c')
				j += ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 's')
				j += ft_putstr_fd(va_arg(args, char *), 1);
			else if (str[i] == 'p')
				j += ft_putstr_fd(ft_itoa_base(va_arg(args, int), 16), 1);
			else if (str[i] == 'd')
				j += ft_putstr_fd(ft_itoa_base(va_arg(args, int), 10), 1);
			else if (str[i] == 'i')
				j += ft_putstr_fd(ft_itoa_base(va_arg(args, int), 10), 1);
			else if (str[i] == 'u')
				va_arg(args, unsigned int);
			else if (str[i] == 'x')
				j += ft_putstr_fd(ft_itoa_base(va_arg(args, int), 16), 1);
			else if (str[i] == 'X')
				j += ft_putstr_fd(ft_itoa_base(va_arg(args, int), 16), 1);
			else
				j += ft_putchar_fd(str[i], 1);
		}
		else
			j += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i + j);
}

#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	i = ft_printf("%i | %x | %X\n", 42, 134302, 134302);
	j = printf("%i | %x | %X\n", 42, 134302, 134302);
	ft_printf("%i | %i\n", i, j);
	printf("%i | %i\n", i, j);
	return (0);
}
