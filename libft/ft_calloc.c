/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguedes <gguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:30:34 by gguedes           #+#    #+#             */
/*   Updated: 2022/06/09 18:55:52 by gguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	if (num && size)
		if (num / (size * num) == size)
			return (NULL);
	p = malloc(num * size);
	if (!p)
		return (NULL);
	ft_bzero(p, num * size);
	return (p);
}
