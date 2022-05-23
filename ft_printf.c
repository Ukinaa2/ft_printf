/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:57:12 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/23 12:49:11 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list args;

	i = 0;
	va_start(args, str);
	while (str[i] && str)
	{
		if (str[i] == '%')
		{
			str++;
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 's')
				va_arg(args, char *);
			else if (str[i] == 'p')
				va_arg(args, int);
			else if (str[i] == 'd')
				va_arg(args, int);
			else if (str[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'u')
				va_arg(args, unsigned int);
			else if (str[i] == 'x')
				va_arg(args, int);
			else if (str[i] == 'X')
				va_arg(args, int);
			else
				ft_putchar_fd(str[i], 1);
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int main(void)
{
	int	i;

	i = ft_printf("%cb%cd%c\n", 'a', 'c', 'e');
	ft_printf("%i\n", i);
	i = printf("%cb%cd%c\n", 'a', 'c', 'e');
	printf("%i\n", i);
	return (0);
}
