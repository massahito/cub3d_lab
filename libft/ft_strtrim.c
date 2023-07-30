/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:23:54 by keys              #+#    #+#             */
/*   Updated: 2022/11/27 07:44:36 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_back(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_strchr(set, (int)*(s1 + len - 1)) == NULL)
			break ;
		len--;
	}
	return (ft_substr(s1, 0, len));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (*s1)
	{
		if (ft_strchr(set, (int)*s1) == NULL)
			return (trim_back(s1, set));
		s1++;
		len--;
	}
	return (ft_calloc(1, 1));
}
