/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:57:12 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/17 14:00:29 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	while (*str && str)
	{
		if (*str == '%')
			str++;
			if (*str == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (*str == 's')
				va_arg(args, char *);
			else if (*str == 'p')
				va_arg(args, int);
			else if (*str == 'd')
				va_arg(args, int);
			else if (*str == 'i')
				va_arg(args, int);
			else if (*str == 'u')
				va_arg(args, unsigned int);
			else if (*str == 'x')
				va_arg(args, int);
			else if (*str == 'X')
				va_arg(args, int);
			else
				ft_putchar_fd(*str, 1);
		str++;
	}
	return (0);
}

int main(void)
{
	ft_printf("%c %c %c\n", 'a', 'b', 'c');
	return (0);
}
