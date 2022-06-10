/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:43:20 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/10 19:00:50 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_size(int n, int base)
{
	int	size;

	size = 0;
	if (n < 0 && base == 10)
		size++;
	while (n)
	{
		n /= base;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa_base(int n, int base)
{
	unsigned long	un;
	int				size;
	char			index[17];
	char			*new_str;

	ft_strlcpy(index, "0123456789abcdef", 17);
	size = ft_count_size(n, base);
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[size] = '\0';
	if (n < 0 && base == 10)
		un = -n;
	else
		un = n;
	while (size--)
	{
		new_str[size] = index[un % base];
		un /= base;
	}
	if (n < 0 && base == 10)
		new_str[0] = '-';
	return (new_str);
}
