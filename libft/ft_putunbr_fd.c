/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:59:08 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/10 13:03:41 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putnbr_fd(n / 10, fd);
	if (n >= 0)
		i += ft_putchar_fd((n % 10) + '0', fd);
	return (i);
}