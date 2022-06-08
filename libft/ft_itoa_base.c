/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:43:20 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/08 13:58:49 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_numsize(int n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > base)
	{
		n /= base;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa_base(int n, int base)
{
	int		size;
	char	index[] = "0123456789abcdef";
	char	*new_str;

	size = ft_numsize(n, base);
	new_str = malloc(size * sizeof(char));
	new_str[size] = '\0';
	while (--size >= 0)
	{
		new_str[size] = index[n % base];
		n /= base;
	}
	return (new_str);
}

/*
int main(int argc, char **argv)
{
	int	i;

	i = atoi(argv[1]);
	printf("%s\n", ft_itoa_base(i, 16));
	printf("%s\n", ft_itoa_base(i, 10));
	printf("\ncheck\n\n");
	printf("%x\n", i);
	printf("%i\n", i);
}
*/
