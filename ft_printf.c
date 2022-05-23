/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:57:12 by gguedes           #+#    #+#             */
/*   Updated: 2022/05/23 13:32:51 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static int	ft_putstr(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i - 1);
}

static int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		i++;
		ft_putnbr(-nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		i++;
	}
	if (nbr >= 0)
		ft_putchar((nbr % 10) + 48);
	return (i);
}

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
				ft_putchar(va_arg(args, int));
			else if (str[i] == 's')
				j += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'p')
				va_arg(args, int);
			else if (str[i] == 'd')
				va_arg(args, int);
			else if (str[i] == 'i')
				j += ft_putnbr(va_arg(args, int));
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
	return (i + j);
}

int main(void)
{
	int		i;
	char	str[] = "abcde";

	i = ft_printf("%cb%cd%c\n%s\n%i\n", 'a', 'c', 'e', str, 42);
	ft_printf("%i\n", i);
	i = printf("%cb%cd%c\n%s\n%i\n", 'a', 'c', 'e', str, 42);
	printf("%i\n", i);
	return (0);
}
