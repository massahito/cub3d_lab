/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:16:34 by keys              #+#    #+#             */
/*   Updated: 2022/11/27 12:43:37 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*tmp;

	tmp = dst;
	if (dst == src || n == 0)
		return (dst);
	while (n-- != 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
	}
	return (tmp);
}
