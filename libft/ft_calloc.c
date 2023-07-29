/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:36:32 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/27 05:23:42 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((SIZE_MAX / (long double)count) < (long double)size)
		return (NULL);
	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	p = malloc(count * size);
	if (!p)
		return (NULL);
	else
		ft_bzero(p, count * size);
	return (p);
}
