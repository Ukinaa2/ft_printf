/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:01:18 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/13 11:03:56 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	printf("printf:\n");
	i = printf("%s\n", NULL);
	printf("ft_printf:\n");
	j = ft_printf("%s\n", NULL);
	printf("printf len: %i\nft_printf len: %i\n", i, j);
	return (0);
}
