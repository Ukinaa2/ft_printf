/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:12:13 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 23:51:09 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned long n, int fd)
{
	int		i;
	char	index[17];

	i = 0;
	ft_strlcpy(index, "0123456789abcdef", 17);
	if (n > 15)
		i += ft_puthex_fd(n / 16, fd);
	i += ft_putchar_fd(index[n % 16], fd);
	return (i);
}
