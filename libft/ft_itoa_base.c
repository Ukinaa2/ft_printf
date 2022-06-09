/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:43:20 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 13:43:11 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numsize(long long n, int base)
{
	int	i;

	i = 0;
	if (n < 0 && base == 10)
	{
		n = -n;
		i++;
	}
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa_base(long long n, int base)
{
	int		size;
	int		negative;
	char	index[17];
	char	*new_str;

	ft_strlcpy(index, "0123456789abcdef", 17);
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_numsize(n, base);
	new_str = malloc(size * sizeof(char));
	new_str[size] = '\0';
	negative = 0;
	if (n < 0 && base == 10)
	{
		n = -n;
		negative = 1;
	}
	while (--size >= 0)
	{
		new_str[size] = index[n % base];
		n /= base;
	}
	if (negative == 1 && base == 10)
		new_str[0] = '-';
	return (new_str);
}
