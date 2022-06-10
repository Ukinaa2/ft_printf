/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:01:18 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 21:08:36 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	n;
	int	i;
	int	j;

	if (argc == 2)
		n = atoi(argv[1]);
	printf("printf:\n");
	i = printf("%%i: %i | %%d: %d | %%u: %u | %%x: %x | %%X: %X | %%p: %p | %%p(null): %p\n", n, n, n, n, n, &i, NULL);
	printf("printf:\n");
	j = ft_printf("%%i: %i | %%d: %d | %%u: %u | %%x: %x | %%X: %X | %%p: %p | %%p(null): %p\n", n, n, n, n, n, &i, NULL);
	printf("printf len: %i\nft_printf len: %i\n", i, j);
	return (0);
}