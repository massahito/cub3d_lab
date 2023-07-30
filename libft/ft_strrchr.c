/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:42:55 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/27 05:11:12 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;

	if (!c)
		return ((char *)(s + ft_strlen(s)));
	len = ft_strlen(s);
	if (len)
	{
		while (len--)
		{
			if (*(s + len) == (char)c)
				return ((char *)(s + len));
		}
	}
	return (NULL);
}
