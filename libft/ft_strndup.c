/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:03:38 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 14:09:06 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t		len;
	char		*p;

	len = ft_strlen(str);
	if (len <= n)
		return (ft_strdup(str));
	p = ft_calloc(n + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, str, n);
	return (p);
}
