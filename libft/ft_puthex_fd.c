/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:12:13 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/10 12:48:20 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned long n, char *base, int fd)
{
	int		i;

	i = 0;
	if (n > 15)
		i += ft_puthex_fd(n / 16, base, fd);
	i += ft_putchar_fd(base[n % 16], fd);
	return (i);
}
